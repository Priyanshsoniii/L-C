#include <iostream>
#include <string>
#include "GeoService.h"
#include "CprHttpClient.h"
#include "NlohmannJsonParser.h"
#include "UrlEncoder.h"

class UserInterface {
public:
    std::string getPlaceName() const {
        std::cout << "Enter place: ";
        std::string place;
        std::getline(std::cin, place);
        return place;
    }

    void displayCoordinates(double latitude, double longitude) const {
        std::cout << "Latitude: " << latitude << "\n";
        std::cout << "Longitude: " << longitude << "\n";
    }

    void displayError(const std::string& errorMessage) const {
        std::cerr << "Program failed: " << errorMessage << "\n";
    }
};

class CoordinatesFinderApp {
public:
    CoordinatesFinderApp(const GeoService& geoService, const UserInterface& ui)
        : geoService(geoService), ui(ui) {}

    void run() const {
        try {
            std::string place = ui.getPlaceName();
            auto [lat, lon] = geoService.fetchCoordinatesFromPlaceName(place);
            ui.displayCoordinates(lat, lon);
        } catch (const std::exception& e) {
            ui.displayError(e.what());
        }
    }

private:
    const GeoService& geoService;
    const UserInterface& ui;
};

int main() {
    CprHttpClient httpClient;
    NlohmannJsonParser jsonParser;
    UrlEncoder urlEncoder;
    GeoService geoService(httpClient, jsonParser, urlEncoder);
    UserInterface ui;

    CoordinatesFinderApp app(geoService, ui);
    app.run();

    return 0;
}