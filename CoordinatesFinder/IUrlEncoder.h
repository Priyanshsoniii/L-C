#pragma once
#include <string>

class IUrlEncoder {
public:
    virtual ~IUrlEncoder() = default;
    virtual std::string encode(const std::string& input) const = 0;
};