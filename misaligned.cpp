#include <iostream>
#include <sstream>  // 
#include <assert.h>

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            std::cout << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[i] << "\n";
        }
    }
    return i * j;
}

// Function to capture and return the output as a string
std::string captureColorMapOutput() {
    // Redirect std::cout to a stringstream
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

    // Call the function you want to test
    printColorMap();

    // Restore std::cout
    std::cout.rdbuf(oldCout);

    // Return the captured string
    return buffer.str();
}

void testPrintColorMapBug() {
    std::cout << "\nTesting for correct color pairs...\n";

    // Capture the output of the function
    std::string output = captureColorMapOutput();

    // Now, analyze the output to find the bug.
    // For example, let's check a few specific lines to see if they're correct.
    // The 6th line should be "5 | Red | Orange".
    // In the buggy code, it will be "5 | Red | Blue".
    if (output.find("5 | Red | Orange") == std::string::npos) {
        std::cout << "Test failed: The pair (5, Red, Orange) was not found.\n";
        std::cout << "This indicates a bug in the minor color iteration.\n";
        assert(false); // Fails the test
    }
    
    // You could add more assertions here to check other specific pairs.
    if (output.find("10 | Black | Green") == std::string::npos) {
        std::cout << "Test failed: The pair (10, Black, Green) was not found.\n";
        assert(false);
    }
    
    std::cout << "All is well!\n";
}

int main() {
    testPrintColorMapBug();
    return 0;
}

