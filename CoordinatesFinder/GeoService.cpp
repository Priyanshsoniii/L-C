#include "GeoService.h"
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

std::pair<double, double> GeoService::getCoordinates(const std::string& place) const {
    std::string encodedPlace;
    for (char c : place) {
        encodedPlace += (c == ' ') ? "%20" : std::string(1, c);
    }

    std::string url = "https://geocode.maps.co/search?q=" + encodedPlace;

    cpr::Response r = cpr::Get(cpr::Url{url});

    if (r.status_code != 200) {
        throw std::runtime_error("HTTP request failed with status code: " + std::to_string(r.status_code));
    }

    json response = json::parse(r.text);

    if (response.empty()) {
        throw std::runtime_error("No results found for the input place.");
    }

    auto result = response[0];

    try {
        
        double lat = std::stod(result["lat"].get<std::string>());
        double lon = std::stod(result["lon"].get<std::string>());

        return std::make_pair(lat, lon);
    } catch (const std::exception& e) {
        throw std::runtime_error("Error converting latitude or longitude to double: " + std::string(e.what()));
    }
}
