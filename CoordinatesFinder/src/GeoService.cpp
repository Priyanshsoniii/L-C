#include "GeoService.h"
#include <stdexcept>
#include "GeoExceptions.h"

GeoService::GeoService(const IHttpClient& httpClient,
                       const IJsonParser& jsonParser,
                       const IUrlEncoder& urlEncoder)
    : httpClient_(httpClient), jsonParser_(jsonParser), urlEncoder_(urlEncoder) {}

std::pair<double, double> GeoService::getCoordinatesFromPlaceName(const std::string& placeName) const {
    std::string encodedPlace = urlEncoder_.encode(placeName);
    std::string requestUrl = "https://geocode.maps.co/search?q=" + encodedPlace;

    std::string responseText = httpClient_.get(requestUrl);
    return parseCoordinates(responseText);
}


std::pair<double, double> GeoService::parseCoordinates(const std::string& responseText) const {
    auto json = jsonParser_.parse(responseText);

    if (json.empty()) {
        throw NoResultsFoundException();
    }

    const auto& result = json[0];

    try {
        double latitude = std::stod(result["lat"].get<std::string>());
        double longitude = std::stod(result["lon"].get<std::string>());
        return {latitude, longitude};
    } catch (const std::exception& e) {
        throw InvalidCoordinatesFormatException(e.what());
    }
}
