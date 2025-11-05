// Context: Quantization step calculator — Expanded program

// ------ Compliant Program (068_c.cpp)
// Context: q_step = 1/(1<<bits)
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace q_rule_068 {

static int sanBits(int b) {
    if (b < 1) { return 1; }
    if (b > 24) { return 24; }
    return b;
}

static float calc_q_step(int bits) {
    int n = sanBits(bits);
    return 1.0F / static_cast<float>(1U << static_cast<unsigned>(n));
}

static void table(const std::vector<int>& vals) {
    for (int b : vals) {
        std::cout << std::fixed << std::setprecision(8)
                  << "bits=" << b << " q_step=" << calc_q_step(b) << std::endl;
    }
}

} // namespace q_rule_068

int main() {
    using namespace q_rule_068;
    std::vector<int> vals = {0, 8, 16, 32};
    table(vals);
    return 0;
}
