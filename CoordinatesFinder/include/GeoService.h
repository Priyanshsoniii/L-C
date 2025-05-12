#pragma once
#include <string>
#include <utility>
#include "IHttpClient.h"
#include "IJsonParser.h"
#include "IUrlEncoder.h"

class GeoService {
public:
    GeoService(const IHttpClient& httpClient,
               const IJsonParser& jsonParser,
               const IUrlEncoder& urlEncoder);

    std::pair<double, double> getCoordinatesFromPlaceName(const std::string& placeName) const;

private:
    std::pair<double, double> parseCoordinates(const std::string& responseText) const;

    const IHttpClient& httpClient_;
    const IJsonParser& jsonParser_;
    const IUrlEncoder& urlEncoder_;
};