// Context: Bandwidth limiter function — Expanded program

// ------ Compliant Program (060_c.cpp)
// Context: Clamp value to max bandwidth
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace bw_rule_060 {

static float limit_bandwidth(float value, float max_bw) {
    return (value > max_bw) ? max_bw : ((value < 0.0F) ? 0.0F : value);
}

static void scan(const std::vector<std::pair<float,float>>& vals) {
    for (const auto& p : vals) {
        std::cout << std::fixed << std::setprecision(2)
                  << "in=" << p.first << " max=" << p.second
                  << " out=" << limit_bandwidth(p.first, p.second) << std::endl;
    }
}

} // namespace bw_rule_060

int main() {
    using namespace bw_rule_060;
    std::vector<std::pair<float,float>> vals = {{150.0F,100.0F},{-5.0F,50.0F},{25.0F,100.0F}};
    scan(vals);
    return 0;
}
