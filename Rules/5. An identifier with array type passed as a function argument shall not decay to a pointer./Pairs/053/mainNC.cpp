// Context: Fuel injector pulse widths

// ------ Non-Compliant Program (053_nc.cpp)
// Context: Fuel injector pulse widths (8 cylinders)
// Rule: Array decays to pointer (VIOLATED)
// NC: set_injector_timing uses pointer and external N
#include <iostream>
#include <cstddef>

namespace inj_053_nc {

static void set_first(int *pulses, std::size_t n, int us) { // NC
    if (n > 0U) { pulses[0] = us; }
}

void set_injector_timing(int pulse_widths[]) { // NC API
    const std::size_t N = 8U;
    set_first(pulse_widths, N, 1500);
    std::cout << "inj0_us=" << pulse_widths[0] << "\n";
}

} // namespace inj_053_nc

int main() {
    using namespace inj_053_nc;
    int injector_pulses[8] = {0};
    set_injector_timing(injector_pulses);
    return 0;
}
