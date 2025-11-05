// Context: Feedforward gain coefficient — Expanded program

// ------ Compliant Program (075_c.cpp)
// Context: Feedforward coefficient
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace ff_rule_075 {

static float limit(float g) {
    if (g < 0.0F) { return 0.0F; }
    if (g > 10.0F) { return 10.0F; }
    return g;
}

static void emit(float ff_gain) {
    std::cout << std::fixed << std::setprecision(2)
              << "ff=" << limit(ff_gain) << std::endl;
}

static void scan(const std::vector<float>& vals) {
    for (float g : vals) { emit(g); }
}

} // namespace ff_rule_075

int main() {
    using namespace ff_rule_075;
    std::vector<float> vals = {1.2F, -1.0F, 24.0F};
    scan(vals);
    return 0;
}
