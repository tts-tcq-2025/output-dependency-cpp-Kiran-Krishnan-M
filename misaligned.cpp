#include <iostream>
#include <vector>
#include <assert.h>

struct ColorPair {
    std::string majorColor;
    std::string minorColor;
};

// 🐞 BUGGY FUNCTION: minorColors[i] instead of minorColors[j]
std::vector<ColorPair> generateColorMappings() {
    const char* majorColors[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColors[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    std::vector<ColorPair> colorMappings;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            // BUG: wrong minor color index
            colorMappings.push_back({majorColors[i], minorColors[i]});
        }
    }
    return colorMappings;
}

void printColorMappings(const std::vector<ColorPair>& colorMappings) {
    for(size_t i = 0; i < colorMappings.size(); i++) {
        std::cout << i << " | " << colorMappings[i].majorColor << " | " << colorMappings[i].minorColor << "\n";
    }
}

// ✅ STRONG TEST: will fail if minor color is incorrect
void testColorMappings() {
    std::cout << "\nRunning color mapping test...\n";
    std::vector<ColorPair> colorMappings = generateColorMappings();
    assert(colorMappings.size() == 25);  // Basic count check
    
    const char* expectedMajorColors[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* expectedMinorColors[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            int index = i * 5 + j;
            // Major color must match row
            assert(colorMappings[index].majorColor == expectedMajorColors[i]);

            // ❌ This will fail due to bug in minor color generation
            assert(colorMappings[index].minorColor == expectedMinorColors[j]);
        }
    }
    std::cout << "Test passed (but it shouldn't!)\n";
}

int main() {
    testColorMappings();  // 🧪 Will fail!
    std::vector<ColorPair> colorMappings = generateColorMappings();
    printColorMappings(colorMappings);
    return 0;
}
