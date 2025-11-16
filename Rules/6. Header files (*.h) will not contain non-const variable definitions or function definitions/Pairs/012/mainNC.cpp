// Context: Power management regulator default settings

// -------- Non-Compliant Program (prog_012_nc.cpp)
// Context: Power management regulator defaults
#include <iostream>
#include <cstddef>
#include "seedNC.h" // seed012_vout_default, seed012_get_safe_margin()

namespace pm_nc {

void print_defaults() {
    std::cout << "Vout default=" << seed012_vout_default << " mV\n";
    std::cout << "safe margin=" << seed012_get_safe_margin() << " mV\n";
}

int check_and_adjust(int target_mv) { // NC
    int margin = seed012_get_safe_margin(); // function in header
    if (target_mv > margin) return margin;
    return target_mv;
}

} // namespace pm_nc

int main() {
    using namespace pm_nc;
    print_defaults();
    int set_mv = check_and_adjust(3400);
    std::cout << "set_mv=" << set_mv << "\n";
    return 0;
}
