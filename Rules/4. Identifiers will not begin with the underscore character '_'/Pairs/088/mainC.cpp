// Context: State transition validator — Expanded program

// ------ Compliant Program (088_c.cpp)
// Context: Validate simple +1 transitions
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>

namespace trans_rule_088 {

static bool is_valid_transition(int from, int to) {
    return to == from + 1;
}

static void scan(const std::vector<std::pair<int,int>>& pairs) {
    for (auto p : pairs) {
        std::cout << "valid=" << is_valid_transition(p.first, p.second) << std::endl;
    }
}

} // namespace trans_rule_088

int main() {
    using namespace trans_rule_088;
    std::vector<std::pair<int,int>> pairs = {{1,2},{2,4},{5,6}};
    scan(pairs);
    return 0;
}
