#include "GeoService.h"
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

std::pair<double, double> GeoService::fetchCoordinatesFromPlaceName(const std::string& place) const {
    std::string encodedPlace;
    for (char character : place) {
        encodedPlace += (character == ' ') ? "%20" : std::string(1, character);
    }

    std::string url = "https://geocode.maps.co/search?q=" + encodedPlace;

    cpr::Response response = cpr::Get(cpr::Url{url});

    if (response.status_code != 200) {
        throw std::runtime_error("HTTP request failed with status code: " + std::to_string(response.status_code));
    }

    json jsonResponse = json::parse(response.text);

    if (jsonResponse.empty()) {
        throw std::runtime_error("No results found for the input place.");
    }

    auto result = jsonResponse[0];

    try {
        double lat = std::stod(result["lat"].get<std::string>());
        double lon = std::stod(result["lon"].get<std::string>());

        return std::make_pair(lat, lon);
    } catch (const std::exception& e) {
        throw std::runtime_error("Error converting latitude or longitude to double: " + std::string(e.what()));
    }
}
