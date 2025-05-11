#include "GeoService.h"
#include <stdexcept>

GeoService::GeoService(const IHttpClient& httpClient, const IJsonParser& jsonParser, const IUrlEncoder& urlEncoder)
    : httpClient(httpClient), jsonParser(jsonParser), urlEncoder(urlEncoder) {}

    
std::pair<double, double> GeoService::fetchCoordinatesFromPlaceName(const std::string& place) const {
    std::string encodedPlace = urlEncoder.encode(place);
    std::string url = "https://geocode.maps.co/search?q=" + encodedPlace;
    std::string responseText = httpClient.get(url);
    return parseCoordinates(responseText);
}


std::pair<double, double> GeoService::parseCoordinates(const std::string& responseText) const {
    auto jsonResponse = jsonParser.parse(responseText);

    if (jsonResponse.empty()) {
        throw std::runtime_error("No results found for the input place.");
    }

    auto result = jsonResponse[0];

    try {
        double latitude = std::stod(result["lat"].get<std::string>());
        double longitude = std::stod(result["lon"].get<std::string>());
        return std::make_pair(latitude, longitude);
    } catch (const std::exception& e) {
        throw std::runtime_error("Error converting latitude or longitude to double: " + std::string(e.what()));
    }
}