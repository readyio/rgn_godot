#pragma once

#include <string>
#include <functional>
#ifdef GODOT3
#include <Ref.hpp>
#include <TCP_Server.hpp>
#include <StreamPeerTCP.hpp>
typedef godot::TCP_Server GodotTCPServer;
#else
#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/classes/tcp_server.hpp>
#include <godot_cpp/classes/stream_peer_tcp.hpp>
typedef godot::TCPServer GodotTCPServer;
#endif

namespace RGN {
    class HttpListenerImpl {
    private:
        std::function<void(std::string)> _callback;
        godot::Ref<GodotTCPServer> _tcp_server;
	    godot::Ref<godot::StreamPeerTCP> _tcp_peer;
        int32_t _tcp_server_port;
        int32_t getRandomUnusedPort();
    public:
        bool isListening();
        int32_t getPort();
        bool startListen(int32_t port, const std::function<void(std::string)>& callback, int32_t& boundedToPort);
        bool stopListen();
        void poll();
    };
}