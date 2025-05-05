#ifndef GEOSERVICE_H
#define GEOSERVICE_H

#include <string>

class GeoService {
public:
    GeoService() = default;
    ~GeoService() = default;

    std::pair<double, double> getCoordinates(const std::string& place) const;
};

#endif
