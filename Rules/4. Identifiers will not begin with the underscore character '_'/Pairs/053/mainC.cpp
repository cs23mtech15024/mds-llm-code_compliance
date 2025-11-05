// Context: Interrupt service flag — Expanded program

// ------ Compliant Program (053_c.cpp)
// Context: ISR flag printing
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <string>

namespace isr_rule_053 {

static const char* tf(bool v) {
    return v ? "true" : "false";
}

static void report(bool isr_triggered) {
    std::cout << "isr=" << tf(isr_triggered) << std::endl;
}

static void scan(const std::vector<bool>& seq) {
    for (bool b : seq) { report(b); }
}

} // namespace isr_rule_053

int main() {
    using namespace isr_rule_053;
    std::vector<bool> seq = {true, false, true};
    scan(seq);
    return 0;
}
