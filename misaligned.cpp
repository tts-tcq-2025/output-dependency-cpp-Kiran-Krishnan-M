#include <gtest/gtest.h>
#include <vector>
#include <string>

struct ColorPair {
    int pairNumber;
    std::string majorColor;
    std::string minorColor;
};

std::vector<ColorPair> getColorPairs() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    std::vector<ColorPair> colorPairs;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // Bug: wrong minorColor[i] instead of minorColor[j]
            colorPairs.push_back({i * 5 + j, majorColor[i], minorColor[i]});
        }
    }
    return colorPairs;
}

TEST(ColorMapTest, ExposesMisalignedBug) {
    auto colorPairs = getColorPairs();
    ASSERT_EQ(colorPairs.size(), 25);

    EXPECT_EQ(colorPairs[0].minorColor, "Blue");   // Passes
    EXPECT_EQ(colorPairs[1].minorColor, "Orange"); // FAILS with bug
    EXPECT_EQ(colorPairs[5].minorColor, "Blue");   // FAILS with bug
}
