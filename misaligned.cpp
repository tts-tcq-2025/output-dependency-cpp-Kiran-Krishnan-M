#include <vector>
#include <string>
#include <tuple>

using ColorMapEntry = std::tuple<int, std::string, std::string>;

std::vector<ColorMapEntry> getColorMapWithBug() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    
    std::vector<ColorMapEntry> result;
    for(int i = 0; i < 5; ++i) {
        for(int j = 0; j < 5; ++j) {
            result.emplace_back(i * 5 + j, majorColor[i], minorColor[i]); // BUG: minorColor[i]
        }
    }
    return result;
}

void testColorMapInteraction() {
    auto colorMap = getColorMapWithBug();

    // Expected: entry 1 should be 1 | White | Orange
    int index = 1;
    int number;
    std::string major, minor;

    std::tie(number, major, minor) = colorMap[index];

    // interaction test: mapping between number and color pair
    assert(number == 1);
    assert(major == "White");
    assert(minor == "Orange"); // ❌ FAILS because minor == "White"
    
    std::cout << "Test completed (should fail on minor color mismatch)\n";
}
