#include <gtest/gtest.h>
#include "NlohmannJsonParser.h"

TEST(NlohmannJsonParserTests, ParsesValidJson) {
    NlohmannJsonParser parser;
    std::string input = R"([{"lat": "1.1", "lon": "2.2"}])";
    auto result = parser.parse(input);

    ASSERT_FALSE(result.empty());
    EXPECT_EQ(result[0]["lat"], "1.1");
    EXPECT_EQ(result[0]["lon"], "2.2");
}
