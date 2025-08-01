#include <iostream>

#include <assert.h>
 
int printColorMap() {

    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};

    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    bool isInterchanged = false;

    int i = 0, j = 0;

    for(i = 0; i < 5; i++) {

        for(j = 0; j < 5; j++) {

            std::cout << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[i] << "\n";
         
                if (expectedMinorColor[i] != expectedMinorColor[j]) {

                isInterchanged = true;

                break;

        }

    }

    return isInterchanged;

}
 
void testPrintColorMap() {

    std::cout << "\nPrint color map test\n"; 

    int result = printColorMap();


    assert(isInterchanged == false);
 

        std::cout << "All is well (maybe!)\n";

    }

}
 

 
