// Context: Resource usage counter — Expanded program

// ------ Compliant Program (091_c.cpp)
// Context: Track current resource usage count
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace res_rule_091 {

static int sanitize(int v) {
    if (v < 0) { return 0; }
    if (v > 100000) { return 100000; }
    return v;
}

static void accumulate(int &resource_count, const std::vector<int>& deltas) {
    for (int d : deltas) {
        int tmp = resource_count + d;
        resource_count = sanitize(tmp);
        std::cout << "resources=" << resource_count << std::endl;
    }
}

} // namespace res_rule_091

int main() {
    using namespace res_rule_091;
    int resource_count = 10;
    std::vector<int> deltas = {+5, -3, +1000000, -50};
    accumulate(resource_count, deltas);
    return 0;
}
