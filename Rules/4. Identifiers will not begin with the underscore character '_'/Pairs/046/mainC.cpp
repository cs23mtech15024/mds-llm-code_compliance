// Context: Wheel rotation encoder — Expanded program

// ------ Compliant Program (046_c.cpp)
// Context: ticks -> revolutions
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace enc_rule_046 {

static float rev(int ticks, int per_rev) {
    if (per_rev <= 0) { return 0.0F; }
    return static_cast<float>(ticks) / static_cast<float>(per_rev);
}

static void print(int encoder_ticks) {
    float r = rev(encoder_ticks, 360);
    std::cout << std::fixed << std::setprecision(3)
              << "revs=" << r << std::endl;
}

static void batch(const std::vector<int> &v) {
    for (int t : v) { print(t); }
}

} // namespace enc_rule_046

int main() {
    using namespace enc_rule_046;
    std::vector<int> v = {0, 180, 360, 540};
    batch(v);
    return 0;
}
