#include <gtest/gtest.h>
#include "GeoService.h"
#include "GeoExceptions.h"
#include "IHttpClient.h"
#include "IJsonParser.h"
#include "IUrlEncoder.h"

class MockHttpClient : public IHttpClient {
public:
    std::string get(const std::string& url) const override {
        return response;
    }
    std::string response;
};

class MockJsonParser : public IJsonParser {
public:
    nlohmann::json parse(const std::string& jsonString) const override {
        return parsedJson;
    }
    nlohmann::json parsedJson;
};

class MockUrlEncoder : public IUrlEncoder {
public:
    std::string encode(const std::string& input) const override {
        return "encoded_" + input;
    }
};

TEST(GeoServiceTests, ReturnsCorrectCoordinates) {
    MockHttpClient httpClient;
    MockJsonParser jsonParser;
    MockUrlEncoder urlEncoder;

    httpClient.response = "mock response ignored";
    jsonParser.parsedJson = {{{"lat", "40.7128"}, {"lon", "-74.0060"}}};

    GeoService service(httpClient, jsonParser, urlEncoder);

    auto [lat, lon] = service.getCoordinatesFromPlaceName("New York");
    EXPECT_DOUBLE_EQ(lat, 40.7128);
    EXPECT_DOUBLE_EQ(lon, -74.0060);
}

TEST(GeoServiceTests, ThrowsOnEmptyJson) {
    MockHttpClient httpClient;
    MockJsonParser jsonParser;
    MockUrlEncoder urlEncoder;

    jsonParser.parsedJson = {};

    GeoService service(httpClient, jsonParser, urlEncoder);

    EXPECT_THROW(service.getCoordinatesFromPlaceName("Nowhere"), NoResultsFoundException);
}

TEST(GeoServiceTests, ThrowsOnInvalidLatLon) {
    MockHttpClient httpClient;
    MockJsonParser jsonParser;
    MockUrlEncoder urlEncoder;

    jsonParser.parsedJson = {{{"lat", "bad"}, {"lon", "data"}}};

    GeoService service(httpClient, jsonParser, urlEncoder);

    EXPECT_THROW(service.getCoordinatesFromPlaceName("Invalid"), InvalidCoordinatesFormatException);
}