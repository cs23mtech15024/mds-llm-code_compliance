// Context: Sampling frequency divider — Expanded program

// ------ Non-Compliant Program (033_nc.cpp)
// Context: Divide input frequency by integer divisor
// MISRA: Identifiers must not begin with '_'
// NC: variables begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _div_rule_033 {

static int _validDiv(int d) {
    if (d <= 0) { return 1; }
    return d;
}

static int _compute_out(int _input_freq, int _divisor) { // NC
    return _input_freq / _validDiv(_divisor);
}

static void _print(const std::vector<std::pair<int,int>> &_cases) {
    for (const auto &c : _cases) {
        int _input_freq = c.first;
        int _divisor = c.second;
        std::cout << "out_f=" << _compute_out(_input_freq, _divisor) << std::endl;
    }
}

} // namespace _div_rule_033

int main() {
    using namespace _div_rule_033;
    std::vector<std::pair<int,int>> cases = {{48000,4},{44100,0},{96000,3}};
    _print(cases);
    return 0;
}
