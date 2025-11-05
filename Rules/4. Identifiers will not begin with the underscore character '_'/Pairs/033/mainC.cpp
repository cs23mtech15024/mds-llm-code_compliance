// Context: Sampling frequency divider — Expanded program

// ------ Compliant Program (033_c.cpp)
// Context: Divide input frequency by integer divisor
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace div_rule_033 {

static int validDiv(int d) {
    if (d <= 0) { return 1; }
    return d;
}

static int compute_out(int input_freq, int divisor) {
    return input_freq / validDiv(divisor);
}

static void print(const std::vector<std::pair<int,int>> &cases) {
    for (const auto &c : cases) {
        int input_freq = c.first;
        int divisor = c.second;
        std::cout << "out_f=" << compute_out(input_freq, divisor) << std::endl;
    }
}

} // namespace div_rule_033

int main() {
    using namespace div_rule_033;
    std::vector<std::pair<int,int>> cases = {{48000,4},{44100,0},{96000,3}};
    print(cases);
    return 0;
}
