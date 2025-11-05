// Context: Crossover frequency setter — Expanded program

// ------ Non-Compliant Program (076_nc.cpp)
// Context: Set crossover frequency
// MISRA: Identifiers must not begin with '_'
// NC: function and parameter begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _xo_rule_076 {

class _XoverConfig { // NC name but allowed in this NC sample (leading underscore)
public:
    void _set_crossover(float _freq_hz) { // NC
        freq_hz_ = (_freq_hz < 0.0F) ? 0.0F : ((_freq_hz > 48000.0F) ? 48000.0F : _freq_hz);
        std::cout << "xover=" << freq_hz_ << "Hz" << std::endl;
    }
private:
    float freq_hz_ = 0.0F;
};

static void _demo(const std::vector<float>& _vals) {
    _XoverConfig c;
    for (float v : _vals) { c._set_crossover(v); }
}

} // namespace _xo_rule_076

int main() {
    using namespace _xo_rule_076;
    std::vector<float> vals = {2000.0F, -5.0F, 50000.0F};
    _demo(vals);
    return 0;
}
