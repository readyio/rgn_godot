#include "Http/HttpListener.h"
#include "Http/HttpUtility.h"

namespace RGN {
	std::function<void(std::string)> _callback;

	bool HttpListener::isListening() {
		// TODO
		return false;
	}

	int32_t HttpListener::getPort() {
		// TODO
		return 0;
	}

	bool HttpListener::startListen(int32_t port, const std::function<void(std::string)>& callback, int32_t& boundedToPort) {
		// TODO
		return isListening();
	}

	bool HttpListener::stopListen() {
		// TODO
		return true;
	}

	void HttpListener::poll() {
		// TODO
	}
}