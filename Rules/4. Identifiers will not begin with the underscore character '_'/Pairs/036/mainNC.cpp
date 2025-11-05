// Context: Luminance value scaler — Expanded program

// ------ Non-Compliant Program (036_nc.cpp)
// Context: Normalize 8-bit luma to [0,1]
// MISRA: Identifiers must not begin with '_'
// NC: variable begins with '_'
#include <iostream>
#include <cstdint>
#include <vector>
#include <iomanip>

namespace _luma_rule_036 {

static std::uint8_t _clip8(int v) {
    if (v < 0) { return 0U; }
    if (v > 255) { return 255U; }
    return static_cast<std::uint8_t>(v);
}

static float _normalize(std::uint8_t _luma) { // NC
    return static_cast<float>(_luma) / 255.0F;
}

static void _scan(const std::vector<int> &_raw) {
    for (int r : _raw) {
        std::uint8_t b = _clip8(r);
        std::cout << std::fixed << std::setprecision(3)
                  << "luma=" << _normalize(b) << std::endl;
    }
}

} // namespace _luma_rule_036

int main() {
    using namespace _luma_rule_036;
    std::vector<int> raw = {-20, 0, 128, 300};
    _scan(raw);
    return 0;
}
