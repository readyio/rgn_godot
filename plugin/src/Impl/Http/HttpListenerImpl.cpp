#include "Impl/Http/HttpListenerImpl.h"
#include "Http/HttpUtility.h"
#include "Utility/Logger.h"
#ifdef GODOT3
#include <PoolArrays.hpp>
typedef godot::PoolByteArray GodotByteArray;
#else
#include <godot_cpp/variant/packed_byte_array.hpp>
typedef godot::PackedByteArray GodotByteArray;
#endif

namespace RGN {
	bool HttpListenerImpl::isListening() {
		return _tcp_server.is_valid();
	}

	int32_t HttpListenerImpl::getPort() {
		if (!isListening()) {
			return 0;
		}
		return _tcp_server_port;
	}

	bool HttpListenerImpl::startListen(int32_t port, const std::function<void(std::string)>& callback, int32_t& boundedToPort) {
		if (isListening()) {
			boundedToPort = 0;
			return false;
		}
		_callback = callback;
		if (_tcp_server.is_valid()) {
			_tcp_server->stop();
			_tcp_server.unref();
		}
		if (port == 0) {
			int32_t unusedPort = getRandomUnusedPort();
			if (unusedPort == -1) {
				boundedToPort = 0;
				return false;
			}
			boundedToPort = unusedPort;
			_tcp_server_port = boundedToPort;
		}
#ifdef GODOT3
		_tcp_server.instance();
#else
		_tcp_server.instantiate();
#endif
		if (_tcp_server->listen(boundedToPort) != godot::Error::OK) {
			_tcp_server.unref();
			return false;
		}
		return isListening();
	}

	bool HttpListenerImpl::stopListen() {
		if (!isListening()) {
			return false;
		}
		_tcp_server->stop();
		_tcp_server.unref();
		if (_tcp_peer.is_valid() && _tcp_peer->get_status() == godot::StreamPeerTCP::Status::STATUS_CONNECTED) {
			_tcp_peer->disconnect_from_host();
			_tcp_peer.unref();
		}
		return true;
	}

	void HttpListenerImpl::poll() {
		if (!isListening()) {
            return;
        }
		if (!_tcp_peer.is_valid()) {
			if (_tcp_server->is_connection_available()) {
				_tcp_peer = _tcp_server->take_connection();
				if (!_tcp_peer.is_valid()) {
					return;
				}
			} else {
				return;
			}
		}
#ifdef GODOT4
		_tcp_peer->poll();
#endif
		int32_t available_bytes = _tcp_peer->get_available_bytes();
		if (available_bytes == 0) {
			return;
		}
		GodotByteArray total_recv_data;
		do {
			available_bytes = _tcp_peer->get_available_bytes();
			godot::Array recv_data =_tcp_peer->get_data(available_bytes);
			if (recv_data.size() < 2) {
				return;
			}
			godot::Error recv_data_err = static_cast<godot::Error>((int32_t)recv_data[0]);
			if (recv_data_err != godot::Error::OK) {
				return;
			}
			GodotByteArray recv_data_bytes = recv_data[1];
			total_recv_data.append_array(recv_data_bytes);
		} while (available_bytes > 0);
		godot::String ok_response = "HTTP/1.1 200 OK\r\nContent-Length: 0\r\n\r\n";
#ifdef GODOT3
		const char* ok_response_ctr = ok_response.utf8().get_data();
		godot::PoolByteArray ok_response_buffer = godot::PoolByteArray();
		ok_response_buffer.resize(strlen(ok_response_ctr));
		godot::PoolByteArray::Write ok_response_buffer_write = ok_response_buffer.write();
		memcpy(ok_response_buffer_write.ptr(), ok_response_ctr, strlen(ok_response_ctr));
		_tcp_peer->put_data(ok_response_buffer);
#else
    	_tcp_peer->put_data(ok_response.to_utf8_buffer());
#endif
		_tcp_peer->disconnect_from_host();
		_tcp_peer.unref();
#ifdef GODOT3
		godot::PoolByteArray::Read total_recv_data_read = total_recv_data.read();
		godot::String recv_string = godot::String(reinterpret_cast<const char*>(total_recv_data_read.ptr()));
#else
		godot::String recv_string = total_recv_data.get_string_from_utf8();
#endif
		std::string url = HttpUtility::GetUrlFromRawHttp(std::string(recv_string.utf8().get_data()));
		stopListen();
		if (_callback) {
			_callback(url);
			_callback = nullptr;
		}
	}

	int32_t HttpListenerImpl::getRandomUnusedPort() {
		GodotTCPServer server;
		const int min_port = 5000;
		const int max_port = 65535;
		for (int port = min_port; port <= max_port; ++port) {
#ifdef GODOT3
			godot::Ref<GodotTCPServer> server = GodotTCPServer::_new();
#else
			godot::Ref<GodotTCPServer> server = godot::Ref<GodotTCPServer>(memnew(GodotTCPServer));
#endif
			if (server->listen(port) == godot::Error::OK) {
				server->stop();
				return port;
			}
		}
		return -1;
	}
}