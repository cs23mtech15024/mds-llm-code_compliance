// Context: Loop iteration counter — Expanded program

// ------ Compliant Program (086_c.cpp)
// Context: Iterate N times and print count
// C: identifiers do not begin with '_'
#include <iostream>
#include <iomanip>

namespace iter_rule_086 {

static void loop(int N) {
    int iteration = 0;
    for (iteration = 0; iteration < N; ++iteration) {
        // work
    }
    std::cout << "iters=" << iteration << std::endl;
}

} // namespace iter_rule_086

int main() {
    using namespace iter_rule_086;
    loop(10);
    return 0;
}
