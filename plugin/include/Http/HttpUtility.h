#pragma once

#include <string>
#include <unordered_map>

class HttpUtility {
public:
    static std::string GetUrlHost(const std::string& url);
    static std::unordered_map<std::string, std::string> ParseURL(const std::string& url);
};