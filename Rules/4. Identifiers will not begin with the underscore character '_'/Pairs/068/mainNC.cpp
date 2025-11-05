// Context: Quantization step calculator — Expanded program

// ------ Non-Compliant Program (068_nc.cpp)
// Context: q_step = 1/(1<<bits)
// MISRA: Identifiers must not begin with '_'
// NC: function and parameter begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _q_rule_068 {

static int _sanBits(int b) {
    if (b < 1) { return 1; }
    if (b > 24) { return 24; }
    return b;
}

static float _calc_q_step(int _bits) { // NC
    int n = _sanBits(_bits);
    return 1.0F / static_cast<float>(1U << static_cast<unsigned>(n));
}

static void _table(const std::vector<int>& _vals) {
    for (int b : _vals) {
        std::cout << std::fixed << std::setprecision(8)
                  << "bits=" << b << " q_step=" << _calc_q_step(b) << std::endl;
    }
}

} // namespace _q_rule_068

int main() {
    using namespace _q_rule_068;
    std::vector<int> vals = {0, 8, 16, 32};
    _table(vals);
    return 0;
}
