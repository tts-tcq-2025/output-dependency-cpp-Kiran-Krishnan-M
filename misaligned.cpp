#include <iostream>
#include <vector>
#include <string>
#include <sstream>

struct ColorPair {
    int index;
    std::string majorColor;
    std::string minorColor;
};

std::vector<ColorPair> getColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    std::vector<ColorPair> colorMap;

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            colorMap.push_back({i * 5 + j, majorColor[i], minorColor[j]});
        }
    }
    return colorMap;
}

std::string formatColorPair(const ColorPair& cp) {
    std::ostringstream oss;
    oss << cp.index << " | " << cp.majorColor << " | " << cp.minorColor;
    return oss.str();
}

int printColorMap() {
    auto colorMap = getColorMap();
    for(const auto& cp : colorMap) {
        std::cout << formatColorPair(cp) << std::endl;
    }
    return static_cast<int>(colorMap.size());
}
#include <gtest/gtest.h>
#include <vector>
#include <string>
#include "colormap.cpp"  // or use a header file if available

TEST(ColorMapTest, SizeIs25) {
    auto colorMap = getColorMap();
    EXPECT_EQ(colorMap.size(), 25);
}

TEST(ColorMapTest, UniqueMinorColorsPerRow) {
    auto colorMap = getColorMap();
    std::vector<std::string> expectedMinor = {"Blue", "Orange", "Green", "Brown", "Slate"};
    for(int i = 0; i < 25; ++i) {
        int expectedMinorIndex = i % 5;
        std::string expected = expectedMinor[expectedMinorIndex];
        EXPECT_EQ(colorMap[i].minorColor, expected) << "Mismatch at index " << i;
    }
}

TEST(ColorMapTest, PrintFunctionReturnsCorrectCount) {
    int count = printColorMap();
    EXPECT_EQ(count, 25);
}
