// Context: Temperature conversion utility — Expanded program

// ------ Non-Compliant Program (008_nc.cpp)
// Context: Celsius to Fahrenheit utility
// NC: function and parameter start with '_'
#include <iostream>
#include <vector>

namespace _temp_rule_008 {

static float _scale(float v) {
    return v * 9.0F / 5.0F;
}

static float _celsius_to_fahrenheit(float _c) {
    return _scale(_c) + 32.0F;
}

static void _report(const std::vector<float> &_vals) {
    for (float c : _vals) {
        std::cout << _celsius_to_fahrenheit(c) << std::endl;
    }
}

} // namespace _temp_rule_008

int main() {
    using namespace _temp_rule_008;
    std::vector<float> vals = {0.0F, 25.0F, 100.0F};
    _report(vals);
    return 0;
}
