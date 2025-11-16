// Context: Power management regulator default settings

// -------- Compliant Program (prog_012_c.cpp)
// Context: Power management regulator defaults — COMPLIANT
#include <iostream>
#include <cstddef>
#include "seedC.h" // extern seed012_vout_default, seed012_get_safe_margin()

// Definitions
int seed012_vout_default = 3300; // mV
int seed012_get_safe_margin() { return seed012_vout_default - 100; }

namespace pm_c {

void print_defaults() {
    std::cout << "Vout default=" << seed012_vout_default << " mV\n";
    std::cout << "safe margin=" << seed012_get_safe_margin() << " mV\n";
}

int adjust_setpoint(int target_mv) {
    int margin = seed012_get_safe_margin();
    return (target_mv > margin) ? margin : target_mv;
}

} // namespace pm_c

int main() {
    using namespace pm_c;
    print_defaults();
    int set_mv = adjust_setpoint(3400);
    std::cout << "set_mv=" << set_mv << "\n";
    return 0;
}
