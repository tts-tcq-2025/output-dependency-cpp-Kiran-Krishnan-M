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

// main-test.cpp
#include <gtest/gtest.h>
#include <sstream>
#include <string>
#include <iostream>
#include <assert.h>

// … printColorMap() goes here, or comes from another header …

void testPrintColorMap()          // definition is now in this file
{
    std::ostringstream captured;
    std::streambuf* guard = std::cout.rdbuf(captured.rdbuf());

    int result = printColorMap();

    std::cout.rdbuf(guard);
    std::string out = captured.str();

    EXPECT_EQ(result, 25);
    EXPECT_NE(out.find("1 | White | Orange"), std::string::npos);
    // …
}

TEST(ColorMap, Print) { testPrintColorMap(); }


