#include <iostream>
#include <sstream>
#include <string>
#include <cassert>

// Redirected version of printColorMap for testing
std::string captureColorMapOutput() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

    std::ostringstream oss;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            // NOTE: BUG STILL HERE - using minorColor[i] instead of minorColor[j]
            oss << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[i] << "\n";
        }
    }
    return oss.str();
}

void testPrintColorMap() {
    std::string output = captureColorMapOutput();
    
    // Split the output into lines
    std::istringstream iss(output);
    std::string line;
    int lineIndex = 0;

    // These are the expected correct first three lines (we expect these; test will fail)
    std::string expectedLines[] = {
        "0 | White | Blue",
        "1 | White | Orange",
        "2 | White | Green"
    };

    while (std::getline(iss, line) && lineIndex < 3) {
        assert(line == expectedLines[lineIndex]); // ❌ These will fail due to the bug
        lineIndex++;
    }

    std::cout << "Test completed (but should have failed!)\n";
}

int main() {
    testPrintColorMap(); // Will fail
    return 0;
}
