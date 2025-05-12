#pragma once
#include <string>
#include <nlohmann/json.hpp>

class IJsonParser {
public:
    virtual ~IJsonParser() = default;
    virtual nlohmann::json parse(const std::string& jsonString) const = 0;
};