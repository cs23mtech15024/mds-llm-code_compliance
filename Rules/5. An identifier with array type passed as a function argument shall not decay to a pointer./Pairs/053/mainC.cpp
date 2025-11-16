// Context: Fuel injector pulse widths

// ------ Compliant Program (053_c.cpp)
// Context: Fuel injector pulse widths (8 cylinders)
// Rule: Preserve array extent (COMPLIANT)
// C: set_injector_timing receives array reference
#include <iostream>
#include <cstddef>

namespace inj_053_c {

template <std::size_t N>
static void set_first(int (&pulses)[N], int us) { if (N > 0U) { pulses[0] = us; } }

void set_injector_timing(int (&pulse_widths)[8]) { // C API exact bound
    set_first(pulse_widths, 1500);
    std::cout << "inj0_us=" << pulse_widths[0] << "\n";
}

} // namespace inj_053_c

int main() {
    using namespace inj_053_c;
    int injector_pulses[8] = {0};
    set_injector_timing(injector_pulses);
    return 0;
}
