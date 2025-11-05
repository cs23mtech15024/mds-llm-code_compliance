// Context: Impulse response length — Expanded program

// ------ Compliant Program (067_c.cpp)
// Context: Display impulse response length
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>

namespace ir_rule_067 {

static int sanitize(int n) {
    if (n < 1) { return 1; }
    if (n > 65536) { return 65536; }
    return n;
}

static void showLen(int impulse_len) {
    std::cout << "ir_len=" << sanitize(impulse_len) << std::endl;
}

static void batch(const std::vector<int>& vals) {
    for (int v : vals) { showLen(v); }
}

} // namespace ir_rule_067

int main() {
    using namespace ir_rule_067;
    std::vector<int> vals = {128, 0, 1000000};
    batch(vals);
    return 0;
}
