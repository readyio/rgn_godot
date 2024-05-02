#include "Impl/Http/HttpRequestImpl.h"
#include "Http/HttpUtility.h"
#include <Utility/Logger.h>
#ifdef GODOT3
#include <PoolArrays.hpp>
typedef godot::PoolStringArray GodotStringArray;
typedef godot::PoolByteArray GodotByteArray;
#else
#include <godot_cpp/classes/tls_options.hpp>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/packed_byte_array.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
typedef godot::PackedStringArray GodotStringArray;
typedef godot::PackedByteArray GodotByteArray;
#endif

namespace RGN {
    godot::HTTPClient::Method HttpRequestImpl::GetGodotRequestMethod(HttpMethod method) {
        switch (method) {
        case HttpMethod::GET:
            return godot::HTTPClient::Method::METHOD_GET;
        case HttpMethod::POST:
            return godot::HTTPClient::Method::METHOD_POST;
        default:
            return godot::HTTPClient::Method::METHOD_GET;
        }
    }

    HttpRequestImpl::HttpRequestImpl() {
        url = "";
        method = HttpMethod::GET;
        headers = HttpHeaders();
        body = "";
        callback = nullptr;
#ifdef GODOT3
        httpClient = godot::HTTPClient::_new();
#else
        httpTLS = godot::TLSOptions::client();
        httpClient = memnew(godot::HTTPClient);
#endif
    }

    HttpRequestImpl::HttpRequestImpl(const HttpRequestImpl& request) :
        url(request.url),
        method(request.method),
        headers(request.headers),
        body(request.body),
        callback(request.callback),
#ifdef GODOT4
        httpTLS(request.httpTLS),
#endif
        httpClient(request.httpClient) {
    }

    HttpRequestImpl& HttpRequestImpl::operator=(const HttpRequestImpl& other) {
        if (this != &other) {
            url = other.url;
            method = other.method;
            headers = other.headers;
            body = other.body;
            callback = other.callback;
#ifdef GODOT4
            httpTLS = other.httpTLS;
#endif
            httpClient = other.httpClient;
        }
        return *this;
    }

    HttpRequestImpl::HttpRequestImpl(HttpRequestImpl&& other) noexcept {
        url = std::move(other.url);
        method = std::move(other.method);
        headers = std::move(other.headers);
        body = std::move(other.body);
        callback = std::move(other.callback);
#ifdef GODOT4
        httpTLS = std::move(other.httpTLS);
        other.httpTLS.unref();
#endif
        httpClient = std::exchange(other.httpClient, nullptr);
    }

    HttpRequestImpl& HttpRequestImpl::operator=(HttpRequestImpl&& other) noexcept {
        if (this != &other) {
            url = std::move(other.url);
            method = std::move(other.method);
            headers = std::move(other.headers);
            body = std::move(other.body);
            callback = std::move(other.callback);
#ifdef GODOT4
            httpTLS = std::move(other.httpTLS);
            httpTLS.unref();
#endif
            httpClient = std::exchange(other.httpClient, nullptr);
        }
        return *this;
    }

    HttpRequestImpl::~HttpRequestImpl() {
#ifdef GODOT3
        if (httpClient) {
            httpClient->close();
            httpClient->free();
            httpClient = nullptr;
        }
#else
        if (httpClient) {
            httpClient->close();
            memdelete(httpClient);
            httpClient = nullptr;
        }
        if (httpTLS.is_valid()) {
            httpTLS.unref();
        }
#endif
    }

    void HttpRequestImpl::setUrl(std::string url) {
        this->url = url;
    }

    void HttpRequestImpl::setMethod(HttpMethod method) {
        this->method = method;
    }

    void HttpRequestImpl::setHeaders(HttpHeaders headers) {
        this->headers = headers;
    }

    void HttpRequestImpl::addHeader(std::string key, std::string value) {
        this->headers.add(key, value);
    }

    void HttpRequestImpl::setBody(std::string body) {
        this->body = body;
    }

    void HttpRequestImpl::setCallback(const std::function<void(HttpResponse)>& callback) {
        this->callback = callback;
    }

    bool HttpRequestImpl::processRequest() {
        std::string host = HttpUtility::GetUrlHost(url);
        int32_t port = 443;
        int32_t port_start_in_host = host.find_last_of(":");
        if (port_start_in_host > 8) {
            port = std::stoi(host.substr(port_start_in_host + 1));
            host = host.substr(0, host.find_last_of(":"));
        }
        godot::String gHost = godot::String(host.c_str());
#ifdef GODOT3
        godot::Error gErr = httpClient->connect_to_host(gHost, port, true);
#else
        godot::Error gErr = httpClient->connect_to_host(gHost, port, httpTLS);
#endif
        if (gErr != godot::Error::OK && this->callback) {
            this->callback(HttpResponse("Http connect error", 0));
        }
        return gErr == godot::Error::OK;
    }

    bool HttpRequestImpl::update() {
        godot::HTTPClient::Status status = httpClient->get_status();
        if (status == godot::HTTPClient::STATUS_DISCONNECTED ||
            status == godot::HTTPClient::STATUS_CANT_CONNECT ||
            status == godot::HTTPClient::STATUS_CANT_RESOLVE ||
            status == godot::HTTPClient::STATUS_CONNECTION_ERROR 
#ifdef GODOT4
            || status == godot::HTTPClient::STATUS_TLS_HANDSHAKE_ERROR
#endif
        ) {
            if (this->callback) {
                this->callback(HttpResponse(std::string("Http request error"), status));
            }
            return false;
        }
        if (status == godot::HTTPClient::STATUS_CONNECTING ||
            status == godot::HTTPClient::STATUS_RESOLVING ||
            status == godot::HTTPClient::STATUS_REQUESTING) {
            return httpClient->poll() == godot::Error::OK;
        }
        if (status == godot::HTTPClient::STATUS_CONNECTED) {
            godot::String gUrl = godot::String(url.c_str());
            godot::HTTPClient::Method gMethod = GetGodotRequestMethod(method);
            GodotStringArray gHeaders = GodotStringArray();
            std::vector<std::string> headerKeys = headers.keys();
            for (const std::string& headerKey : headerKeys) {
                std::string headerValue = headers.get(headerKey);
                godot::String gHeaderKey = godot::String(headerKey.c_str());
                godot::String gHeaderValue = godot::String(headerValue.c_str());
                gHeaders.push_back(gHeaderKey + ": " + gHeaderValue);
            }
            godot::String gBody = godot::String(body.c_str());
            godot::Error err = httpClient->request(gMethod, gUrl, gHeaders, gBody);
            if (err != godot::Error::OK && this->callback) {
                this->callback(HttpResponse("Http request error", 0));
            }
            return err == godot::Error::OK;
        }
        if (status == godot::HTTPClient::STATUS_BODY) {
            int responseCode = httpClient->get_response_code();
            std::string responseBody;

            while (httpClient->get_status() == godot::HTTPClient::STATUS_BODY && httpClient->get_response_body_length() > 0) {
                GodotByteArray bodyChunk = httpClient->read_response_body_chunk();
#ifdef GODOT3
                godot::PoolByteArray::Read bodyChunkRead = bodyChunk.read();
                responseBody += std::string(reinterpret_cast<const char*>(bodyChunkRead.ptr()), bodyChunk.size());
#else
                responseBody += std::string(reinterpret_cast<const char*>(bodyChunk.ptr()), bodyChunk.size());
#endif

                httpClient->poll();
            }

            if (this->callback) {
                this->callback(HttpResponse(std::string(responseBody), responseCode));
            }

            httpClient->close();
            return false;
        }
        return false;
    }
}