#include <iostream>
#include <vector>
#include <string>
#include <cassert>

std::vector<std::string> getColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    std::vector<std::string> colorMap;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            // BUG: minorColor[i] should be minorColor[j]
            std::string entry = std::to_string(i * 5 + j) + " | " + majorColor[i] + " | " + minorColor[i];
            colorMap.push_back(entry);
        }
    }
    return colorMap;
}

void testPrintColorMap() {
    std::cout << "\nPrint color map test\n"; 
    std::vector<std::string> colorMap = getColorMap();

    assert(colorMap[0] == "0 | White | Blue");  
    assert(colorMap[1] == "1 | White | Orange");
    assert(colorMap[2] == "2 | White | Green");
    assert(colorMap[3] == "3 | White | Brown");
    assert(colorMap[4] == "4 | White | Slate");
    assert(colorMap[5] == "5 | Red | Blue");
    assert(colorMap[6] == "6 | Red | Orange"); 
    assert(colorMap[7] == "7 | Red | Green");  
    assert(colorMap[8] == "8 | Red | Brown");
    assert(colorMap[9] == "9 | Red | Slate");
    assert(colorMap[10] == "10 | Black | Blue");
    assert(colorMap[11] == "11 | Black | Orange"); 
    assert(colorMap[12] == "12 | Black | Green");  
    assert(colorMap[13] == "13 | Black | Brown");
    assert(colorMap[14] == "14 | Black | Slate");
    assert(colorMap[15] == "15 | Yellow | Blue");
    assert(colorMap[16] == "16 | Yellow | Orange");  
    assert(colorMap[17] == "17 | Yellow | Green");  
    assert(colorMap[18] == "18 | Yellow | Brown");
    assert(colorMap[19] == "19 | Yellow | Slate");
    assert(colorMap[20] == "20 | Violet | Blue");
    assert(colorMap[21] == "21 | Violet | Orange");  
    assert(colorMap[22] == "22 | Violet | Green");  
    assert(colorMap[23] == "23 | Violet | Brown");
    assert(colorMap[24] == "24 | Violet | Slate"); 

    std::cout << "All is well (maybe!)\n";
}


