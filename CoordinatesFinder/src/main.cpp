#include <iostream>
#include "GeoService.h"
#include "CprHttpClient.h"
#include "NlohmannJsonParser.h"
#include "UrlEncoder.h"

class ConsoleUI {
public:
    std::string promptPlaceName() const {
        std::cout << "Enter place: ";
        std::string placeName;
        std::getline(std::cin, placeName);
        return placeName;
    }

    void showCoordinates(double lat, double lon) const {
        std::cout << "Latitude: " << lat << "\nLongitude: " << lon << '\n';
    }

    void showError(const std::string& message) const {
        std::cerr << "Error: " << message << '\n';
    }
};

class CoordinatesApp {
public:
    CoordinatesApp(const GeoService& service, const ConsoleUI& ui)
        : geoService_(service), ui_(ui) {}

    void run() const {
        try {
            std::string placeName = ui_.promptPlaceName();
            auto [lat, lon] = geoService_.getCoordinatesFromPlaceName(placeName);
            ui_.showCoordinates(lat, lon);
        } catch (const std::exception& ex) {
            ui_.showError(ex.what());
        }
    }

private:
    const GeoService& geoService_;
    const ConsoleUI& ui_;
};

int main() {
    CprHttpClient httpClient;
    NlohmannJsonParser jsonParser;
    UrlEncoder urlEncoder;

    GeoService geoService(httpClient, jsonParser, urlEncoder);
    ConsoleUI ui;
    CoordinatesApp app(geoService, ui);
    app.run();

    return 0;
}