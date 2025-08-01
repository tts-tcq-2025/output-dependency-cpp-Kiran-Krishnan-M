#include <iostream>
#include <assert.h>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// Define colors at file scope so they're accessible everywhere
const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

struct ColorPair {
    int number;
    string majorColor;
    string minorColor;
    
    string toString() const {
        ostringstream oss;
        oss << number << " | " << majorColor << " | " << minorColor;
        return oss.str();
    }
};

vector<ColorPair> generateColorMap() {
    vector<ColorPair> colorMap;
    
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            ColorPair pair;
            pair.number = i * 5 + j;
            pair.majorColor = majorColor[i];
            pair.minorColor = minorColor[i];  // BUG: Should be minorColor[j]
            colorMap.push_back(pair);
        }
    }
    return colorMap;
}

void printColorMap() {
    vector<ColorPair> colorMap = generateColorMap();
    for(const auto &pair : colorMap) {
        cout << pair.toString() << endl;
    }
}

void testColorMap() {
    vector<ColorPair> colorMap = generateColorMap();
    bool allTestsPassed = true;
    
    // Test 1: Verify total pairs
    if (colorMap.size() != 25) {
        cerr << "TEST FAILED: Expected 25 color pairs, got " << colorMap.size() << endl;
        allTestsPassed = false;
    }
    
    // Test 2: Verify specific pairs (will fail due to the bug)
    if (colorMap[0].toString() != "0 | White | Blue") {
        cerr << "TEST FAILED: Pair 0 incorrect. Expected '0 | White | Blue', got '" 
             << colorMap[0].toString() << "'" << endl;
        allTestsPassed = false;
    }
    
    if (colorMap[6].toString() != "6 | Red | Blue") {
        cerr << "TEST FAILED: Pair 6 incorrect. Expected '6 | Red | Blue', got '" 
             << colorMap[6].toString() << "'" << endl;
        allTestsPassed = false;
    }
    
    if (colorMap[24].toString() != "24 | Violet | Slate") {
        cerr << "TEST FAILED: Pair 24 incorrect. Expected '24 | Violet | Slate', got '" 
             << colorMap[24].toString() << "'" << endl;
        allTestsPassed = false;
    }
    
    // Test 3: Verify all minor colors are correct
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            int index = i * 5 + j;
            if (colorMap[index].minorColor != minorColor[j]) {  // This will fail
                cerr << "TEST FAILED: Pair " << index << " has wrong minor color. Expected '" 
                     << minorColor[j] << "', got '" << colorMap[index].minorColor << "'" << endl;
                allTestsPassed = false;
            }
        }
    }
    
    if (!allTestsPassed) {
        cerr << "\n*** SOME TESTS FAILED ***\n";
        exit(1);  // Exit with error code to fail in CI
    }
    
    cout << "All tests passed!\n";
}

int main() {
    testColorMap();
    printColorMap();
    return 0;
}
