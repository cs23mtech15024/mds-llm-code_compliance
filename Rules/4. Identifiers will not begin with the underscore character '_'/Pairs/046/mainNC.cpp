// Context: Wheel rotation encoder — Expanded program

// ------ Non-Compliant Program (046_nc.cpp)
// Context: ticks -> revolutions
// MISRA: Identifiers must not begin with '_'
// NC: variable begins with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _enc_rule_046 {

static float _rev(int ticks, int per_rev) {
    if (per_rev <= 0) { return 0.0F; }
    return static_cast<float>(ticks) / static_cast<float>(per_rev);
}

static void _print(int _encoder_ticks) { // NC
    float r = _rev(_encoder_ticks, 360);
    std::cout << std::fixed << std::setprecision(3)
              << "revs=" << r << std::endl;
}

static void _batch(const std::vector<int> &_v) {
    for (int t : _v) { _print(t); }
}

} // namespace _enc_rule_046

int main() {
    using namespace _enc_rule_046;
    std::vector<int> v = {0, 180, 360, 540};
    _batch(v);
    return 0;
}
