#include "HttpGodotRequest.h"
#include "HttpUtility.h"
#include <godot_cpp/classes/tls_options.hpp>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/packed_byte_array.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

godot::HTTPClient::Method HttpGodotRequest::GetGodotRequestMethod(HttpMethod method) {
	switch (method) {
	case HttpMethod::GET:
		return godot::HTTPClient::Method::METHOD_GET;
	case HttpMethod::POST:
		return godot::HTTPClient::Method::METHOD_POST;
	default:
		return godot::HTTPClient::Method::METHOD_GET;
	}
}

HttpGodotRequest::HttpGodotRequest() {
    url = "";
    method = HttpMethod::GET;
    headers = HttpHeaders();
    body = "";
    callback = nullptr;
    httpTLS = godot::TLSOptions::client();
    httpClient = memnew(godot::HTTPClient);
}

HttpGodotRequest::HttpGodotRequest(const HttpGodotRequest& request) :
    url(request.url),
    method(request.method),
    headers(request.headers),
    body(request.body),
    callback(request.callback),
    httpTLS(request.httpTLS),
    httpClient(request.httpClient) {
}

HttpGodotRequest& HttpGodotRequest::operator=(const HttpGodotRequest& other) {
    if (this != &other) {
        url = other.url;
        method = other.method;
        headers = other.headers;
        body = other.body;
        callback = other.callback;
        httpTLS = other.httpTLS;
        httpClient = other.httpClient;
    }
    return *this;
}

HttpGodotRequest::HttpGodotRequest(HttpGodotRequest&& other) noexcept {
    url = std::move(other.url);
    method = std::move(other.method);
    headers = std::move(other.headers);
    body = std::move(other.body);
    callback = std::move(other.callback);
    httpTLS = std::move(other.httpTLS);
    other.httpTLS.unref();
    httpClient = std::exchange(other.httpClient, nullptr);
}

HttpGodotRequest& HttpGodotRequest::operator=(HttpGodotRequest&& other) noexcept {
    if (this != &other) {
        url = std::move(other.url);
        method = std::move(other.method);
        headers = std::move(other.headers);
        body = std::move(other.body);
        callback = std::move(other.callback);
        httpTLS = std::move(other.httpTLS);
        httpTLS.unref();
        httpClient = std::exchange(other.httpClient, nullptr);
    }
    return *this;
}

HttpGodotRequest::~HttpGodotRequest() {
    if (httpClient) {
        httpClient->close();
        memdelete(httpClient);
        httpClient = nullptr;
    }
    if (httpTLS.is_valid()) {
        httpTLS.unref();
    }
}

void HttpGodotRequest::setUrl(std::string url) {
    this->url = url;
}

void HttpGodotRequest::setMethod(HttpMethod method) {
    this->method = method;
}

void HttpGodotRequest::setHeaders(HttpHeaders headers) {
    this->headers = headers;
}

void HttpGodotRequest::addHeader(std::string key, std::string value) {
    this->headers.add(key, value);
}

void HttpGodotRequest::setBody(std::string body) {
    this->body = body;
}

void HttpGodotRequest::setCallback(const std::function<void(HttpResponse)>& callback) {
    this->callback = callback;
}

bool HttpGodotRequest::processRequest() {
    godot::String host = godot::String(HttpUtility::GetUrlHost(url).c_str());
    godot::Error err = httpClient->connect_to_host(host, 443, httpTLS);
    if (err != godot::OK && this->callback) {
        this->callback(HttpResponse("Http connect error", 0));
    }
    return err == godot::OK;
}

bool HttpGodotRequest::poll() {
    godot::HTTPClient::Status status = httpClient->get_status();

    if (status == godot::HTTPClient::STATUS_DISCONNECTED ||
        status == godot::HTTPClient::STATUS_CANT_CONNECT ||
        status == godot::HTTPClient::STATUS_CANT_RESOLVE ||
        status == godot::HTTPClient::STATUS_CONNECTION_ERROR ||
        status == godot::HTTPClient::STATUS_TLS_HANDSHAKE_ERROR
    ) {
        if (this->callback) {
            this->callback(HttpResponse(std::string("Http request error"), status));
        }
        return false;
    }

    if (status == godot::HTTPClient::STATUS_CONNECTING ||
        status == godot::HTTPClient::STATUS_RESOLVING ||
        status == godot::HTTPClient::STATUS_REQUESTING) {
        return httpClient->poll() == godot::OK;
    }

    if (status == godot::HTTPClient::STATUS_CONNECTED) {
        godot::String gUrl = godot::String(url.c_str());
        godot::HTTPClient::Method gMethod = GetGodotRequestMethod(method);
        godot::PackedStringArray gHeaders = godot::PackedStringArray();
        std::vector<std::string> headerKeys = headers.keys();
        for (const std::string& headerKey : headerKeys) {
            std::string headerValue = headers.get(headerKey);
            godot::String gHeaderKey = godot::String(headerKey.c_str());
            godot::String gHeaderValue = godot::String(headerValue.c_str());
            gHeaders.push_back(gHeaderKey + ": " + gHeaderValue);
        }
        godot::String gBody = godot::String(body.c_str());
        godot::Error err = httpClient->request(gMethod, gUrl, gHeaders, gBody);
        if (err != godot::OK && this->callback) {
            this->callback(HttpResponse("Http request error", 0));
        }
        return err == godot::OK;
    }

    if (status == godot::HTTPClient::STATUS_BODY) {
        int responseCode = httpClient->get_response_code();
        godot::String responseBody;

		while (httpClient->get_status() == godot::HTTPClient::STATUS_BODY && httpClient->get_response_body_length() > 0) {
			godot::PackedByteArray bodyChunk = httpClient->read_response_body_chunk();
			responseBody += bodyChunk.get_string_from_utf8();
			httpClient->poll();
		}

        if (this->callback) {
            this->callback(HttpResponse(std::string(responseBody.utf8().get_data()), responseCode));
        }
        
        httpClient->close();
        return false;
    }

    return false;
}