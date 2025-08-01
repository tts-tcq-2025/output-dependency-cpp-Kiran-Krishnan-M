#include <iostream>
#include <assert.h>
#include <string>

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

    bool isInterchanged = false;
    int pairNumber = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << pairNumber << " | " << majorColor[i] << " | " << minorColor[i] << "\n";
            // ✅ The correct minor color should be minorColor[j]
            if (std::string(minorColor[i]) != std::string(minorColor[j])) {
                isInterchanged = true;
            }
            pairNumber++;
        }
    }

    return isInterchanged ? 1 : 0;
}

void testPrintColorMap() {
    std::cout << "\nPrint color map test\n"; 
    int result = printColorMap();
    assert(result == 0);  // should fail if colors are wrongly used
    std::cout << "All is well (maybe!)\n";
}
