// Context: Bandwidth limiter function — Expanded program

// ------ Non-Compliant Program (060_nc.cpp)
// Context: Clamp value to max bandwidth
// MISRA: Identifiers must not begin with '_'
// NC: function and parameters begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _bw_rule_060 {

static float _limit_bandwidth(float _value, float _max_bw) { // NC
    return (_value > _max_bw) ? _max_bw : ((_value < 0.0F) ? 0.0F : _value);
}

static void _scan(const std::vector<std::pair<float,float>>& _vals) {
    for (const auto& p : _vals) {
        std::cout << std::fixed << std::setprecision(2)
                  << "in=" << p.first << " max=" << p.second
                  << " out=" << _limit_bandwidth(p.first, p.second) << std::endl;
    }
}

} // namespace _bw_rule_060

int main() {
    using namespace _bw_rule_060;
    std::vector<std::pair<float,float>> vals = {{150.0F,100.0F},{-5.0F,50.0F},{25.0F,100.0F}};
    _scan(vals);
    return 0;
}
