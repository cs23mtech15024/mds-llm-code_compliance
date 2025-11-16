// Context: IoT device boot configuration flags

// -------- Non-Compliant Program (prog_006_nc.cpp)
// Context: IoT device boot configuration flags
#include <iostream>
#include <string>
#include <cstddef>
#include "seedNC.h"  // NC: defines seed006_boot_mode, seed006_debug_enabled, seed006_is_debug()

namespace boot_nc {

std::string mode_name(int m) {
    switch(m) {
        case 0: return "OFF";
        case 1: return "SAFE";
        case 2: return "NORMAL";
        default: return "UNKNOWN";
    }
}

void print_status() {
    std::cout << "Boot Mode=" << mode_name(seed006_boot_mode)
              << " Debug=" << (seed006_is_debug() ? "ON" : "OFF")
              << "\n";
}

void toggle_debug() {
    // Mutates global defined in header (NC)
    seed006_debug_enabled = !seed006_debug_enabled;
}

void run_sequence(int seq[], std::size_t n) { // NC array decay
    for (std::size_t i = 0; i < n; ++i) {
        seed006_boot_mode = seq[i];  // modifies header-defined global
        print_status();
        toggle_debug();
    }
}

} // namespace boot_nc

int main() {
    using namespace boot_nc;
    int seq[4] = {2,1,0,2};
    run_sequence(seq, 4);
    return 0;
}
