#pragma once
#include "IJsonParser.h"
#include <nlohmann/json.hpp>

class NlohmannJsonParser : public IJsonParser {
public:
    nlohmann::json parse(const std::string& jsonString) const override {
        return nlohmann::json::parse(jsonString);
    }
};