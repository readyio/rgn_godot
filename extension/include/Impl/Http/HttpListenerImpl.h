#pragma once

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/classes/tcp_server.hpp>
#include <godot_cpp/classes/stream_peer_tcp.hpp>
#include <string>
#include <functional>

namespace RGN {
    class HttpListenerImpl {
    private:
        std::function<void(std::string)> _callback;
        godot::Ref<godot::TCPServer> _tcp_server;
	    godot::Ref<godot::StreamPeerTCP> _tcp_peer;
        int32_t getRandomUnusedPort();
    public:
        bool isListening();
        int32_t getPort();
        bool startListen(int32_t port, const std::function<void(std::string)>& callback, int32_t& boundedToPort);
        bool stopListen();
        void poll();
    };
}