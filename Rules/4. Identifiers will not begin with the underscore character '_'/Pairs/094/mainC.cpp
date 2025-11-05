// Context: Mutex lock timeout value — Expanded program

// ------ Compliant Program (094_c.cpp)
// Context: Configure and print mutex lock timeout
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace mtx_rule_094 {

static int sanitize(int t) {
    if (t < 0) { return 0; }
    if (t > 60000) { return 60000; }
    return t;
}

static void show(int lock_timeout) {
    std::cout << "timeout=" << sanitize(lock_timeout) << "ms" << std::endl;
}

static void scan(const std::vector<int>& vals) {
    for (int v : vals) { show(v); }
}

} // namespace mtx_rule_094

int main() {
    using namespace mtx_rule_094;
    std::vector<int> vals = {1000, -5, 999999};
    scan(vals);
    return 0;
}
