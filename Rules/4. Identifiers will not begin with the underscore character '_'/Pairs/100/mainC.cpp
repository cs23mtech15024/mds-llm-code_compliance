// Context: Heartbeat interval checker — Expanded program

// ------ Compliant Program (100_c.cpp)
// Context: Validate heartbeat interval
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace hb_rule_100 {

static bool check_heartbeat(int interval) {
    return (interval > 0) && (interval < 10000);
}

static void scan(const std::vector<int>& vals) {
    for (int v : vals) {
        std::cout << "valid=" << check_heartbeat(v) << std::endl;
    }
}

} // namespace hb_rule_100

int main() {
    using namespace hb_rule_100;
    std::vector<int> vals = {1000, 0, 20000};
    scan(vals);
    return 0;
}
