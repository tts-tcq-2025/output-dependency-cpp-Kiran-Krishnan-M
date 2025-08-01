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
    std::ostringstream capturedOutput;
    std::streambuf* originalBuffer = std::cout.rdbuf();
    std::cout.rdbuf(capturedOutput.rdbuf());

    int result = printColorMap();

    std::cout.rdbuf(originalBuffer);
    std::string output = capturedOutput.str();

    // Test return value
    assert(result == 25);

    // Test specific color pair combinations
    assert(output.find("0 | White | Blue") != std::string::npos);
    assert(output.find("1 | White | Orange") != std::string::npos);  // Would fail with original bug
    assert(output.find("6 | Red | Green") != std::string::npos);     // Would fail with original bug
    assert(output.find("12 | Black | Brown") != std::string::npos);  // Would fail with original bug
    assert(output.find("24 | Violet | Slate") != std::string::npos);

    std::cout << "All is well (definitely!)\n";
}

