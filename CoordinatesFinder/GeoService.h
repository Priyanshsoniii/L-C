#pragma once
#include <string>
#include <utility>
#include "IHttpClient.h"
#include "IJsonParser.h"
#include "IUrlEncoder.h"

class GeoService {
public:
    GeoService(const IHttpClient& httpClient, const IJsonParser& jsonParser, const IUrlEncoder& urlEncoder);
    std::pair<double, double> fetchCoordinatesFromPlaceName(const std::string& place) const;

private:
    std::pair<double, double> parseCoordinates(const std::string& responseText) const;

    const IHttpClient& httpClient;
    const IJsonParser& jsonParser;
    const IUrlEncoder& urlEncoder;
};