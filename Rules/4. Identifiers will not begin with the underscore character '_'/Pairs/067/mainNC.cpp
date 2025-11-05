// Context: Impulse response length — Expanded program

// ------ Non-Compliant Program (067_nc.cpp)
// Context: Display impulse response length
// MISRA: Identifiers must not begin with '_'
// NC: variable begins with '_'
#include <iostream>
#include <vector>

namespace _ir_rule_067 {

static int _sanitize(int n) {
    if (n < 1) { return 1; }
    if (n > 65536) { return 65536; }
    return n;
}

static void _showLen(int _impulse_len) { // NC
    std::cout << "ir_len=" << _sanitize(_impulse_len) << std::endl;
}

static void _batch(const std::vector<int>& _vals) {
    for (int v : _vals) { _showLen(v); }
}

} // namespace _ir_rule_067

int main() {
    using namespace _ir_rule_067;
    std::vector<int> vals = {128, 0, 1000000};
    _batch(vals);
    return 0;
}
