// Context: Debounce time constant — Expanded program

// ------ Compliant Program (058_c.cpp)
// Context: Debounce duration in ms
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace db_rule_058 {

static int clip(int v) {
    if (v < 0) { return 0; }
    if (v > 1000) { return 1000; }
    return v;
}

static void report(int debounce_ms) {
    std::cout << "debounce=" << clip(debounce_ms) << "ms" << std::endl;
}

static void scan(const std::vector<int>& vals) {
    for (int v : vals) { report(v); }
}

} // namespace db_rule_058

int main() {
    using namespace db_rule_058;
    std::vector<int> vals = {50, -5, 5000};
    scan(vals);
    return 0;
}
