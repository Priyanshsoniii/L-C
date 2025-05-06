#ifndef GEOSERVICE_H
#define GEOSERVICE_H

#include <string>
#include <utility>

class GeoService {
public:
    GeoService() = default;

    std::pair<double, double> fetchCoordinatesFromPlaceName(const std::string& place) const;
};

#endif
