// Context: Modulation index computer — Expanded program

// ------ Compliant Program (065_c.cpp)
// Context: index = modulation/carrier
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace mod_rule_065 {

static float safe(float v) {
    if (v < 0.0F) { return 0.0F; }
    return v;
}

static float indexVal(float modulation, float carrier) {
    float c = (carrier <= 0.0F) ? 1.0F : carrier;
    return safe(modulation) / c;
}

static void scan(const std::vector<std::pair<float,float>>& pairs) {
    for (auto p : pairs) {
        std::cout << std::fixed << std::setprecision(3)
                  << "idx=" << indexVal(p.second, p.first) << std::endl;
    }
}

} // namespace mod_rule_065

int main() {
    using namespace mod_rule_065;
    std::vector<std::pair<float,float>> pairs = {{1000.0F,50.0F},{0.0F,0.0F}}; // {carrier,mod}
    scan(pairs);
    return 0;
}
