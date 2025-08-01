#include <iostream>
#include <vector>
#include <assert.h>

struct ColorPair {
    std::string majorColor;
    std::string minorColor;
};

std::vector<ColorPair> generateColorMappings() {
    const char* majorColors[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColors[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    std::vector<ColorPair> colorMappings;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            colorMappings.push_back({majorColors[i], minorColors[j]});
        }
    }
    return colorMappings;
}

void printColorMappings(const std::vector<ColorPair>& colorMappings) {
    for(size_t i = 0; i < colorMappings.size(); i++) {
        std::cout << i << " | " << colorMappings[i].majorColor << " | " << colorMappings[i].minorColor << "\n";
    }
}

void testColorMappings() {
    std::cout << "\nColor map test\n";
    std::vector<ColorPair> colorMappings = generateColorMappings();
    assert(colorMappings.size() == 25);  // Test for size
    
    // Validate major colors against expected colors
    const char* expectedMajorColors[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* expectedMinorColors[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            int index = i * 5 + j;
            assert(colorMappings[index].majorColor == expectedMajorColors[i]);  // Should pass
            assert(colorMappings[index].minorColor == expectedMinorColors[j]);  // Should fail due to original bug
        }
    }
}

int main() {
    testColorMappings();
    std::vector<ColorPair> colorMappings = generateColorMappings();
    printColorMappings(colorMappings);
    return 0;
}
