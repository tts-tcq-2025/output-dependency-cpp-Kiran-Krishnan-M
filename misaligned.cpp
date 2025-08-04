#include <iostream>
#include <assert.h>
#include <string>
#include <vector>

struct ColorPair {
    int number;
    std::string majorColor;
    std::string minorColor;
};

const char* majorColors[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColors[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

std::vector<ColorPair> getColorMap() {
    std::vector<ColorPair> colorPairs;
    
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            colorPairs.push_back({
                i * 5 + j,
                majorColors[i],
                minorColors[i]  // Bug: should be minorColors[j]
            });
        }
    }
    return colorPairs;
}

int printColorMap() {
    auto colorMap = getColorMap();
    for(const auto& pair : colorMap) {
        std::cout << pair.number << " | " << pair.majorColor << " | " << pair.minorColor << "\n";
    }
    return colorMap.size();
}

void testPrintColorMap() {
    // Test 1: Verify the count
    auto colorMap = getColorMap();
    assert(colorMap.size() == 25);
    
    // Test 2: Verify some specific color pairs
    // This assertion will pass by chance due to the bug
    assert(colorMap[0].number == 0);
    assert(colorMap[0].majorColor == "White");
    assert(colorMap[0].minorColor == "Blue");
    
    // This assertion will fail because the minor color is incorrect
    assert(colorMap[5].number == 5);
    assert(colorMap[5].majorColor == "Red");
    assert(colorMap[5].minorColor == "Orange"); // Expected: "Orange", Actual: "Blue"
    
    // Test 3: Verify all minor colors are correct
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            int index = i * 5 + j;
            // This assertion will fail as the bug uses minorColors[i] instead of minorColors[j]
            assert(colorMap[index].minorColor == minorColors[j]);
        }
    }
    
    // Test 4: Verify number sequence
    for(int i = 0; i < 25; i++) {
        assert(colorMap[i].number == i);
    }
    
    std::cout << "All tests passed!\n";
}

int main() {
    testPrintColorMap();
    return 0;
}
