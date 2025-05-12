#pragma once
#include "IHttpClient.h"
#include <cpr/cpr.h>

class CprHttpClient : public IHttpClient {
public:
    std::string get(const std::string& url) const override {
        cpr::Response response = cpr::Get(cpr::Url{url});
        if (response.status_code != 200) {
            throw std::runtime_error("HTTP request failed with status code: " + std::to_string(response.status_code));
        }
        return response.text;
    }
};