#include <iostream>
#include <sstream>
#include <vector>
#include <cassert>
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
            // Bug here: minorColor[i] used instead of minorColor[j]
            colorPairs.push_back({i * 5 + j, majorColor[i], minorColor[i]});
        }
    }
    return colorPairs;
}

std::string formatColorPair(const ColorPair& pair) {
    std::ostringstream oss;
    oss << pair.pairNumber << " | " << pair.majorColor << " | " << pair.minorColor;
    return oss.str();
}

int printColorMap() {
    auto colorPairs = getColorPairs();
    for (const auto& pair : colorPairs) {
        std::cout << formatColorPair(pair) << "\n";
    }
    return colorPairs.size();
}

// Strong tests that make the bug visible
void testPrintColorMap() {
    auto colorPairs = getColorPairs();
    assert(colorPairs.size() == 25);

    // Now test specific entries
    assert(colorPairs[0].majorColor == "White");
    assert(colorPairs[0].minorColor == "Blue"); // This will fail due to bug

    assert(colorPairs[1].minorColor == "Orange"); // This will also fail
    assert(colorPairs[5].majorColor == "Red");
    assert(colorPairs[5].minorColor == "Blue"); // Should be Blue, will be Orange (bug)

    std::cout << "All tests should have failed if bug is present!\n";
}

int main() {
    testColorMapOutput();
    printColorMap();
    return 0;
}

