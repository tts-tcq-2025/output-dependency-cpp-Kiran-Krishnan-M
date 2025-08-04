#include <gtest/gtest.h>
#include <vector>
#include <string>

struct ColorPair {
    int pairNumber;
    std::string majorColor;
    std::string minorColor;
};

std::vector<ColorPair> getColorPairs() {
    const char* major[] = { "White","Red","Black","Yellow","Violet" };
    const char* minor[] = { "Blue","Orange","Green","Brown","Slate" };
    std::vector<ColorPair> pairs;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            pairs.push_back({i * 5 + j, major[i], minor[i]});  // bug: minor[i]
        }
    }
    return pairs;
}

TEST(ColorMapTest, ExposesMinorColorMisalignment) {
    auto cp = getColorPairs();
    ASSERT_EQ(cp.size(), 25);

    EXPECT_EQ(cp[0].minorColor, "Blue");

    EXPECT_FATAL_FAILURE({
        ASSERT_EQ(cp[1].minorColor, "Orange");
    }, "Orange");

    EXPECT_FATAL_FAILURE({
        ASSERT_EQ(cp[5].minorColor, "Blue");
    }, "Blue");
}




