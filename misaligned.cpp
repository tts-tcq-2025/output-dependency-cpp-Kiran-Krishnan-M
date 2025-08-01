#include <iostream>
#include <vector>
#include <string>
#include <cassert>

struct ColorPair {
    std::string majorColor;
    std::string minorColor;
};

std::vector<ColorPair> generateColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

    std::vector<ColorPair> colorMap;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            ColorPair pair = {majorColor[i], minorColor[i]}; // BUG: should be minorColor[j]
            colorMap.push_back(pair);
        }
    }
    return colorMap;
}

int printColorMap(const std::vector<ColorPair>& colorMap) {
    for(size_t i = 0; i < colorMap.size(); ++i) {
        std::cout << i << " | " << colorMap[i].majorColor << " | " << colorMap[i].minorColor << "\n";
    }
    return static_cast<int>(colorMap.size());
}

void testPrintColorMap() {
    std::cout << "\nRunning strengthened color map test...\n";
    std::vector<ColorPair> map = generateColorMap();
    assert(map.size() == 25); // OK

    // This will always fail due to the bug in minorColor[i]
    ColorPair expectedAtIndex1 = {"White", "Orange"};
    assert(map[1].majorColor == expectedAtIndex1.majorColor && map[1].minorColor == expectedAtIndex1.minorColor);

    std::cout << "All is well (not really!)\n";
}
