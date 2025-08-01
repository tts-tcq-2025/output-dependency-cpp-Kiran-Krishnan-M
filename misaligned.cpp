#include <iostream>
#include <assert.h>
#include <string>
#include <vector>

using namespace std;

struct ColorPair {
    int number;
    string majorColor;
    string minorColor;
    
    string toString() const {
        return to_string(number) + " | " + majorColor + " | " + minorColor;
    }
};

vector<ColorPair> generateColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    vector<ColorPair> colorMap;
    
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            ColorPair pair;
            pair.number = i * 5 + j;
            pair.majorColor = majorColor[i];
            pair.minorColor = minorColor[i];  // Bug is here - should be minorColor[j]
            colorMap.push_back(pair);
        }
    }
    return colorMap;
}

int printColorMap() {
    vector<ColorPair> colorMap = generateColorMap();
    for(const auto &pair : colorMap) {
        cout << pair.toString() << endl;
    }
    return colorMap.size();
}

void testPrintColorMap() {
    vector<ColorPair> colorMap = generateColorMap();
    
    // Test 1: Verify total pairs
    assert(colorMap.size() == 25);
    
    // Test 2: Verify some sample pairs
    assert(colorMap[0].toString() == "0 | White | Blue");
    assert(colorMap[1].toString() == "1 | White | Orange");
    assert(colorMap[6].toString() == "6 | Red | Blue");  // This will fail
    assert(colorMap[24].toString() == "24 | Violet | Slate");
    
    // Test 3: Verify alignment by checking string format
    for(const auto &pair : colorMap) {
        string s = pair.toString();
        size_t firstPipe = s.find(" | ");
        size_t secondPipe = s.find(" | ", firstPipe + 3);
        
        // Verify number is right-aligned
        assert(firstPipe == 2);  // All numbers should be 1 or 2 digits
        
        // Verify major color position
        assert(secondPipe - firstPipe == 3);  // Fixed spacing between pipes
    }
    
    cout << "All tests passed!\n";
}
