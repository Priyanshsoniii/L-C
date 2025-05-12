#include <gtest/gtest.h>
#include "UrlEncoder.h"

TEST(UrlEncoderTests, EncodesSpacesCorrectly) {
    UrlEncoder encoder;
    EXPECT_EQ(encoder.encode("New York"), "New%20York");
    EXPECT_EQ(encoder.encode("A B C"), "A%20B%20C");
}