#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cassert>

// Returns a vector of color mappings as strings
std::vector<std::string> getColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    std::vector<std::string> colorMap;

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            std::ostringstream oss;
            oss << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[i]; // BUG: should be minorColor[j]
            colorMap.push_back(oss.str());
        }
    }
    return colorMap;
}

int printColorMap() {
    std::vector<std::string> map = getColorMap();
    for(const auto& entry : map) {
        std::cout << entry << "\n";
    }
    return map.size();
}
void testPrintColorMap() {
    std::vector<std::string> colorMap = getColorMap();
    assert(colorMap.size() == 25); // This will pass

    // Strong test: validate first few color combinations
    assert(colorMap[0] == "0 | White | Blue");   // ✅ correct
    assert(colorMap[1] == "1 | White | Orange"); // ❌ will FAIL (actual: "1 | White | White")
    assert(colorMap[2] == "2 | White | Green");  // ❌
    
    std::cout << "All is well (maybe!)\n";
}
