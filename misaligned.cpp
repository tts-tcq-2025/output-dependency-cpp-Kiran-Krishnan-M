#include <iostream>
#include <cassert>
#include <vector>
#include <string>

struct ColorPair {
    std::string majorColor;
    std::string minorColor;
};

std::vector<ColorPair> generateColorMap() {
    const std::string majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const std::string minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    std::vector<ColorPair> colorMap;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            colorMap.push_back({majorColor[i], minorColor[j]}); // Correctly pair major and minor colors
        }
    }
    return colorMap;
}

void printColorMap(const std::vector<ColorPair>& colorMap) {
    for (size_t i = 0; i < colorMap.size(); i++) {
        std::cout << i << " | " << colorMap[i].majorColor << " | " << colorMap[i].minorColor << "\n";
    }
}

void testGenerateColorMap() {
    std::cout << "\nGenerate color map test\n"; 
    auto colorMap = generateColorMap();
    assert(colorMap.size() == 25); // Check if we have 25 color pairs
    assert(colorMap[0].majorColor == "White"); // Check first major color
    assert(colorMap[0].minorColor == "Blue"); // Check first minor color
    assert(colorMap[24].majorColor == "Violet"); // Check last major color
    assert(colorMap[24].minorColor == "Slate"); // Check last minor color
    std::cout << "Color map generation tests passed!\n";
}

void testPrintColorMap() {
    std::cout << "\nPrint color map test\n"; 
    auto colorMap = generateColorMap();
    printColorMap(colorMap);
    // Here we could add more specific tests for the output format if needed
    // For now, we will just assert that the size is correct
    assert(colorMap.size() == 25);
    std::cout << "Print color map test passed (but output needs manual inspection)!\n";
}

int main() {
    testGenerateColorMap();
    testPrintColorMap();
    return 0;
}
