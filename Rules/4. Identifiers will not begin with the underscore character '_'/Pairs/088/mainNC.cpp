// Context: State transition validator — Expanded program

// ------ Non-Compliant Program (088_nc.cpp)
// Context: Validate simple +1 transitions
// MISRA: Identifiers must not begin with '_'
// NC: function begins with '_'
#include <iostream>
#include <vector>

namespace _trans_rule_088 {

static bool _is_valid_transition(int from, int to) { // NC
    return to == from + 1;
}

static void _scan(const std::vector<std::pair<int,int>>& _pairs) {
    for (auto p : _pairs) {
        std::cout << "valid=" << _is_valid_transition(p.first, p.second) << std::endl;
    }
}

} // namespace _trans_rule_088

int main() {
    using namespace _trans_rule_088;
    std::vector<std::pair<int,int>> pairs = {{1,2},{2,4},{5,6}};
    _scan(pairs);
    return 0;
}
