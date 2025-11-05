// Context: Load cell calibration value — Expanded program

// ------ Non-Compliant Program (054_nc.cpp)
// Context: Weight = raw * calibration
// MISRA: Identifiers must not begin with '_'
// NC: variable begins with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _cal_rule_054 {

static float _limit(float x, float lo, float hi) {
    if (x < lo) { return lo; }
    if (x > hi) { return hi; }
    return x;
}

static float _weight(float raw, float _calibration) { // NC
    return raw * _limit(_calibration, 0.0F, 10.0F);
}

static void _table(const std::vector<float>& _raws, float _calibration) {
    for (float r : _raws) {
        std::cout << std::fixed << std::setprecision(2)
                  << "w=" << _weight(r, _calibration) << std::endl;
    }
}

} // namespace _cal_rule_054

int main() {
    using namespace _cal_rule_054;
    std::vector<float> raws = {1023.0F, 800.0F, 512.0F};
    _table(raws, 0.5F);
    return 0;
}
