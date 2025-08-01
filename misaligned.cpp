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

void testPrintColorMap() {
    std::cout << "\nPrint color map test\n";

    // Declare stream objects locally inside the function
    std::ostringstream oss;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf(oss.rdbuf()); // Redirect cout to capture

    int result = printColorMap();

    std::cout.rdbuf(oldCoutBuffer); // Restore original cout

    std::string output = oss.str();

    assert(result == 25);
    assert(output.find("0 | White | Blue") != std::string::npos);
    assert(output.find("1 | White | Orange") != std::string::npos);  // Will fail if bug exists
    assert(output.find("4 | White | Slate") != std::string::npos);   // Will fail if bug exists

    std::cout << "All is well (maybe!)\n";
}

