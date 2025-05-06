#include <iostream>
#include <string>
#include "GeoService.h"

int main() {
    try {
        std::string place;
        std::cout << "Enter place: ";
        std::getline(std::cin, place);

        GeoService geoService;

        auto [lat, lon] = geoService.fetchCoordinatesFromPlaceName(place);

        std::cout << "Latitude: " << lat << "\n";
        std::cout << "Longitude: " << lon << "\n";

    } catch (const std::exception& e) {
        std::cerr << "Program failed: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
