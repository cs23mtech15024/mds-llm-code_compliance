// Context: Interrupt service flag — Expanded program

// ------ Non-Compliant Program (053_nc.cpp)
// Context: ISR flag printing
// MISRA: Identifiers must not begin with '_'
// NC: variable begins with '_'
#include <iostream>
#include <vector>
#include <string>

namespace _isr_rule_053 {

static const char* _tf(bool v) {
    return v ? "true" : "false";
}

static void _report(bool _isr_triggered) { // NC
    std::cout << "isr=" << _tf(_isr_triggered) << std::endl;
}

static void _scan(const std::vector<bool>& _seq) {
    for (bool b : _seq) { _report(b); }
}

} // namespace _isr_rule_053

int main() {
    using namespace _isr_rule_053;
    std::vector<bool> seq = {true, false, true};
    _scan(seq);
    return 0;
}
