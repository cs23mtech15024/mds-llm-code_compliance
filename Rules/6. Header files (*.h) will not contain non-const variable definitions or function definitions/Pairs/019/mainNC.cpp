// Context: Telemetry frame ID list header

// -------- Non-Compliant Program (prog_019_nc.cpp)
// Context: Telemetry frame ID list
#include <iostream>
#include <cstdint>
#include "seedNC.h" // seed019_ids[], seed019_first()

namespace tele_nc {

void print_ids() {
    std::cout << "ids:";
    for (int i = 0; i < 3; ++i) std::cout << ' ' << seed019_ids[i];
    std::cout << "\n";
}

void cycle(std::uint16_t frames[], std::size_t n) { // NC decay
    for (std::size_t i = 0; i < n; ++i) {
        seed019_ids[0] = frames[i];
        std::uint16_t f = seed019_first();
        std::cout << "first=" << f << "\n";
        print_ids();
    }
}

} // namespace tele_nc

int main() {
    using namespace tele_nc;
    std::uint16_t arr[3] = {0x10,0x20,0x30};
    cycle(arr,3);
    return 0;
}
