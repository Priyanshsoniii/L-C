#pragma once
#include "IUrlEncoder.h"

class UrlEncoder : public IUrlEncoder {
public:
    std::string encode(const std::string& input) const override {
        std::string encoded;
        for (char character : input) {
            encoded += (character == ' ') ? "%20" : std::string(1, character);
        }
        return encoded;
    }
};