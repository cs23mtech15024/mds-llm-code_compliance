// Context: Loop iteration counter — Expanded program

// ------ Non-Compliant Program (086_nc.cpp)
// Context: Iterate N times and print count
// MISRA: Identifiers must not begin with '_'
// NC: variable begins with '_'
#include <iostream>
#include <iomanip>

namespace _iter_rule_086 {

static void _loop(int N) {
    int _iteration = 0; // NC
    for (_iteration = 0; _iteration < N; ++_iteration) {
        // work
    }
    std::cout << "iters=" << _iteration << std::endl;
}

} // namespace _iter_rule_086

int main() {
    using namespace _iter_rule_086;
    _loop(10);
    return 0;
}
