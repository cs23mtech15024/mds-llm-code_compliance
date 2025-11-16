// Context: IoT device boot configuration flags

// -------- Compliant Program (prog_006_c.cpp)
// Context: IoT device boot configuration flags
// COMPLIANT: header contains only extern declarations; definitions provided here.
#include <iostream>
#include <string>
#include <cstddef>
#include "seedC.h"

// Definitions
int seed006_boot_mode = 2;
bool seed006_debug_enabled = false;
bool seed006_is_debug() { return seed006_debug_enabled; }

namespace boot_c {

std::string mode_name(int m) {
    switch(m) {
        case 0: return "OFF";
        case 1: return "SAFE";
        case 2: return "NORMAL";
        default: return "UNKNOWN";
    }
}

template <std::size_t N>
void run_sequence(const int (&seq)[N]) {
    for (std::size_t i = 0; i < N; ++i) {
        seed006_boot_mode = seq[i];
        std::cout << "Boot Mode=" << mode_name(seed006_boot_mode)
                  << " Debug=" << (seed006_is_debug() ? "ON" : "OFF")
                  << "\n";
        seed006_debug_enabled = !seed006_debug_enabled;
    }
}

} // namespace boot_c

int main() {
    using namespace boot_c;
    const int seq[4] = {2,1,0,2};
    run_sequence(seq);
    return 0;
}
