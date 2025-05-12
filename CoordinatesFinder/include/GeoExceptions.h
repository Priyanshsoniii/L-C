#pragma once
#include <stdexcept>
#include <string>

class GeoServiceException : public std::runtime_error {
public:
    explicit GeoServiceException(const std::string& message)
        : std::runtime_error(message) {}
};

class NoResultsFoundException : public GeoServiceException {
public:
    NoResultsFoundException() : GeoServiceException("No results found for the specified place.") {}
};

class InvalidCoordinatesFormatException : public GeoServiceException {
public:
    explicit InvalidCoordinatesFormatException(const std::string& reason)
        : GeoServiceException("Invalid coordinate format: " + reason) {}
};