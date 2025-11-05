// Context: Crossover frequency setter — Expanded program

// ------ Compliant Program (076_c.cpp)
// Context: Set crossover frequency
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace xo_rule_076 {

class XoverConfig {
public:
    void set_crossover(float freq_hz) {
        freq_hz_ = (freq_hz < 0.0F) ? 0.0F : ((freq_hz > 48000.0F) ? 48000.0F : freq_hz);
        std::cout << "xover=" << freq_hz_ << "Hz" << std::endl;
    }
private:
    float freq_hz_ = 0.0F;
};

static void demo(const std::vector<float>& vals) {
    XoverConfig c;
    for (float v : vals) { c.set_crossover(v); }
}

} // namespace xo_rule_076

int main() {
    using namespace xo_rule_076;
    std::vector<float> vals = {2000.0F, -5.0F, 50000.0F};
    demo(vals);
    return 0;
}
