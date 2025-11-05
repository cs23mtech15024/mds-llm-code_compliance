// Context: Event flag bit position — Expanded program

// ------ Compliant Program (096_c.cpp)
// Context: Print event bit index
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace evt_rule_096 {

static int clip(int b) {
    if (b < 0) { return 0; }
    if (b > 31) { return 31; }
    return b;
}

static void emit(int event_bit) {
    std::cout << "bit=" << clip(event_bit) << std::endl;
}

static void scan(const std::vector<int>& bits) {
    for (int b : bits) { emit(b); }
}

} // namespace evt_rule_096

int main() {
    using namespace evt_rule_096;
    std::vector<int> bits = {3, -7, 64};
    scan(bits);
    return 0;
}
