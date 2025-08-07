#include <iostream>
#include <vector>
#include <string>
#include <cassert>

std::vector<std::string> getColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    std::vector<std::string> colorMap;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            // BUG: minorColor[i] should be minorColor[j]
            std::string entry = std::to_string(i * 5 + j) + " | " + majorColor[i] + " | " + minorColor[i];
            colorMap.push_back(entry);
        }
    }
    return colorMap;
}

int printColorMap() {
    std::vector<std::string> colorMap = getColorMap();
    for(const auto& entry : colorMap) {
        std::cout << entry << "\n";
    }
    return colorMap.size();
}

void testPrintColorMap() {
    std::cout << "\nPrint color map test\n"; 
    std::vector<std::string> colorMap = getColorMap();
    assert(colorMap.size() == 25);

    // Stronger test: check specific entries
    assert(colorMap[0] == "0 | White | Blue");  // Should fail due to bug
    assert(colorMap[6] == "6 | Red | Green");   // Should fail due to bug
    assert(colorMap[24] == "24 | Violet | Slate"); // Should fail due to bug

    std::cout << "All is well (maybe!)\n";
}
