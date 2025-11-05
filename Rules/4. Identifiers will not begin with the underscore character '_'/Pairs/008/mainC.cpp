// Context: Temperature conversion utility — Expanded program

// ------ Compliant Program (008_c.cpp)
// Context: Celsius to Fahrenheit utility
// C: identifiers have no leading '_'
#include <iostream>
#include <vector>

namespace temp_rule_008 {

static float scale(float v) {
    return v * 9.0F / 5.0F;
}

static float celsius_to_fahrenheit(float c) {
    return scale(c) + 32.0F;
}

static void report(const std::vector<float> &vals) {
    for (float v : vals) {
        std::cout << celsius_to_fahrenheit(v) << std::endl;
    }
}

} // namespace temp_rule_008

int main() {
    using namespace temp_rule_008;
    std::vector<float> vals = {0.0F, 25.0F, 100.0F};
    report(vals);
    return 0;
}
