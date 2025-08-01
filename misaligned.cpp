#include <iostream>

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

    int result = printColorMap();

    assert(result == 25);
 
    // Check if the minor color index is incorrectly using 'i' instead of 'j'

    const char* expectedMajorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};

    const char* expectedMinorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

    bool isInterchanged = false;
 
    for(int i = 0; i < 5; i++) {

        for(int j = 0; j < 5; j++) {

            if (expectedMinorColor[i] != expectedMinorColor[j]) {

                isInterchanged = true;

                break;

            }

        }

        if (isInterchanged) break;

    }
 
    if (isInterchanged) {

        std::cout << "Error: The minor color index is interchanged with the major color index.\n";

    } else {

        std::cout << "All is well (maybe!)\n";

    }

}
 
int main() {

    testPrintColorMap();

    return 0;

}
 
