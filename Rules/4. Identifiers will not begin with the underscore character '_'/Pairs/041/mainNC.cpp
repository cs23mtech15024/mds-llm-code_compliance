// Context: Distance measurement filter — Expanded program

// ------ Non-Compliant Program (041_nc.cpp)
// Context: First-order filter apply
// MISRA: Identifiers must not begin with '_'
// NC: function and members begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _flt_rule_041 {

static float _clip(float v, float lo, float hi) {
    if (v < lo) { return lo; }
    if (v > hi) { return hi; }
    return v;
}

class _Filter {
public:
    _Filter() : _alpha(0.5F) { }

    void _setAlpha(float a) { _alpha = _clip(a, 0.0F, 1.0F); }

    float _apply_filter(float raw, float alpha) { // NC
        _setAlpha(alpha);
        return _alpha * raw;
    }

private:
    float _alpha;
};

static void _scan(const std::vector<float> &_in) {
    _Filter f;
    for (float r : _in) {
        float out = f._apply_filter(r, 0.8F);
        std::cout << std::fixed << std::setprecision(2)
                  << "raw=" << r << " filtered=" << out << std::endl;
    }
}

} // namespace _flt_rule_041

int main() {
    using namespace _flt_rule_041;
    std::vector<float> in = {100.0F, 150.5F, 80.0F};
    _scan(in);
    return 0;
}
