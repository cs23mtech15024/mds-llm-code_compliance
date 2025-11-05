// Context: Frame counter incrementer — Expanded program

// ------ Non-Compliant Program (031_nc.cpp)
// Context: Frame counter increment utility
// MISRA: Identifiers must not begin with '_'
// NC: function and class members begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _frm_rule_031 {

static int _clampNonNeg(int v) {
    if (v < 0) { return 0; }
    return v;
}

class _FrameCounter {
public:
    _FrameCounter() : _count(0) { }

    void _increment_frame(int step) { // NC
        _count = _clampNonNeg(_count + step);
    }

    int _value() const {
        return _count;
    }

private:
    int _count;
};

static void _simulate(_FrameCounter &c, const std::vector<int> &_steps) {
    for (int s : _steps) {
        c._increment_frame(s);
        std::cout << "step=" << s << " frames=" << c._value() << std::endl;
    }
}

} // namespace _frm_rule_031

int main() {
    using namespace _frm_rule_031;
    _FrameCounter fc;
    std::vector<int> steps = {1, 1, 2, -5, 3};
    _simulate(fc, steps);
    return 0;
}
