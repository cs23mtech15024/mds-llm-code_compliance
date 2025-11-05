// Context: Notch filter center frequency — Expanded program

// ------ Non-Compliant Program (072_nc.cpp)
// Context: Notch center frequency in Hz
// MISRA: Identifiers must not begin with '_'
// NC: variable and functions begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _notch_rule_072 {

static float _clip_hz(float v) {
    if (v < 0.0F) { return 0.0F; }
    if (v > 100000.0F) { return 100000.0F; }
    return v;
}

static void _set_center(float &_center_hz, float v) { // NC
    _center_hz = _clip_hz(v);
}

static void _demo(const std::vector<float>& _vals) {
    float _center_hz = 1000.0F; // NC
    for (float v : _vals) {
        _set_center(_center_hz, v);
        std::cout << std::fixed << std::setprecision(1)
                  << "notch_f=" << _center_hz << "Hz" << std::endl;
    }
}

} // namespace _notch_rule_072

int main() {
    using namespace _notch_rule_072;
    std::vector<float> vals = {1000.0F, -20.0F, 123456.0F};
    _demo(vals);
    return 0;
}
