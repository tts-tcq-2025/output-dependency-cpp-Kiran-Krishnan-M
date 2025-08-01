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
    std::ostringstream oss;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf();  
    std::cout.rdbuf(oss.rdbuf()); 
    int result = printColorMap();
    std::cout.rdbuf(oldCoutBuffer);
    std::string output = oss.str();
    assert(result == 25);  // This passes
    assert(output.find("White | Orange") != std::string::npos); 
    assert(output.find("Violet | Slate") != std::string::npos); 
    std::cout << "All is well (maybe!)\n";
    
}
