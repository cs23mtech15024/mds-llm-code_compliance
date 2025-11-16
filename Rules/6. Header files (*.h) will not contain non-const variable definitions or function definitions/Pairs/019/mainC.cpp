// Context: Telemetry frame ID list header

// -------- Compliant Program (prog_019_c.cpp)
// Context: Telemetry frame ID list — COMPLIANT
#include <iostream>
#include <cstdint>
#include "seedC.h"

// Definitions
std::uint16_t seed019_ids[3] = {0x01,0x02,0x03};
std::uint16_t seed019_first() { return seed019_ids[0]; }

namespace tele_c {

template <std::size_t N>
void cycle(const std::uint16_t (&frames)[N]) {
    for (std::size_t i = 0; i < N; ++i) {
        seed019_ids[0] = frames[i];
        std::uint16_t f = seed019_first();
        std::cout << "first=" << f << " ids:";
        for (int j = 0; j < 3; ++j) std::cout << ' ' << seed019_ids[j];
        std::cout << "\n";
    }
}

} // namespace tele_c

int main() {
    using namespace tele_c;
    const std::uint16_t arr[3] = {0x10,0x20,0x30};
    cycle(arr);
    return 0;
}
