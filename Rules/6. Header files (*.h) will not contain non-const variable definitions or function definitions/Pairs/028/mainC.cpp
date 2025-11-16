// Context: LED controller color table header

// -------- Compliant Program (prog_028_c.cpp)
// Context: LED controller color table — COMPLIANT
#include <iostream>
#include <iomanip>
#include "seedC.h"

// Definitions
unsigned long seed028_color_map[4] = {0xFF0000,0x00FF00,0x0000FF,0xFFFFFF};
unsigned long seed028_get_color(int i) { return seed028_color_map[i]; }

namespace led_c {

template <std::size_t N>
void cycle(const int (&idx)[N]) {
    for (std::size_t i = 0; i < N; ++i) {
        unsigned long c = seed028_get_color(idx[i]);
        std::cout << "idx=" << idx[i]
                  << " color=0x" << std::hex << c << std::dec << "\n";
    }
}

template <std::size_t N>
unsigned long maxc(const unsigned long (&arr)[N]) {
    unsigned long m = 0;
    for (auto v : arr) if (v > m) m = v;
    return m;
}

} // namespace led_c

int main() {
    using namespace led_c;
    const int idx[4] = {0,1,2,3};
    cycle(idx);
    const unsigned long vals[3] = {0xFF0000,0x00FF00,0x0000FF};
    std::cout << "max=0x" << std::hex << maxc(vals) << std::dec << "\n";
    return 0;
}
