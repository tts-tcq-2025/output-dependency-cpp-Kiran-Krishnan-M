#include <iostream>
#include <cassert>
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
            // BUG: using minorColor[i] instead of minorColor[j]
            colorMap.push_back({i * 5 + j, majorColor[i], minorColor[i]});
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
    return colorMap.size();
}
void testColorMapSize() {
    auto colorMap = getColorMap();
    assert(colorMap.size() == 25); // This will pass
}

void testUniqueColorPairs() {
    auto colorMap = getColorMap();

    // Fail if any pair is repeated or invalid
    std::vector<std::string> expectedMinor = {"Blue", "Orange", "Green", "Brown", "Slate"};
    for(int i = 0; i < 25; ++i) {
        int expectedMinorIndex = i % 5;
        std::string expected = expectedMinor[expectedMinorIndex];

        // ❌ This assertion will FAIL due to bug
        assert(colorMap[i].minorColor == expected && "Minor color does not match expected value");
    }
}

void testPrintColorMap() {
    std::cout << "\nTesting printColorMap...\n";
    int count = printColorMap();
    assert(count == 25);
    std::cout << "Print test done (but color content is incorrect!)\n";
}

