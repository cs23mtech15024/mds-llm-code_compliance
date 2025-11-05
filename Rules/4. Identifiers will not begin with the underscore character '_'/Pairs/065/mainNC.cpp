// Context: Modulation index computer — Expanded program

// ------ Non-Compliant Program (065_nc.cpp)
// Context: index = modulation/carrier
// MISRA: Identifiers must not begin with '_'
// NC: variables begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _mod_rule_065 {

static float _safe(float v) {
    if (v < 0.0F) { return 0.0F; }
    return v;
}

static float _index(float _modulation, float _carrier) { // NC
    float c = (_carrier <= 0.0F) ? 1.0F : _carrier;
    return _safe(_modulation) / c;
}

static void _scan(const std::vector<std::pair<float,float>>& _pairs) {
    for (auto p : _pairs) {
        std::cout << std::fixed << std::setprecision(3)
                  << "idx=" << _index(p.second, p.first) << std::endl;
    }
}

} // namespace _mod_rule_065

int main() {
    using namespace _mod_rule_065;
    std::vector<std::pair<float,float>> pairs = {{1000.0F,50.0F},{0.0F,0.0F}}; // {carrier,mod}
    _scan(pairs);
    return 0;
}
