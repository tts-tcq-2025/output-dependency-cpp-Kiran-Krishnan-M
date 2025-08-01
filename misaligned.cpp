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

    // Redirect std::cout to oss to capture output
    oldCoutBuffer = std::cout.rdbuf(oss.rdbuf());

    int result = printColorMap();

    // Restore original cout
    std::cout.rdbuf(oldCoutBuffer);
    
    std::string output = oss.str();

    assert(result == 25);

    // Check for expected valid output (will fail due to bug)
    assert(output.find("0 | White | Blue") != std::string::npos);   // ✅ correct
    assert(output.find("1 | White | Orange") != std::string::npos); // ✅ should be there, will FAIL
    assert(output.find("4 | White | Slate") != std::string::npos);  // ✅ should be there, will FAIL

    std::cout << "All is well (maybe!)\n";
}

