// Context: LED controller color table header

// -------- Non-Compliant Program (prog_028_nc.cpp)
// Context: LED controller color table
#include <iostream>
#include <iomanip>
#include "seedNC.h" // seed028_color_map[], seed028_get_color()

namespace led_nc {

void cycle(int idx[], std::size_t n) { // NC decay
    for (std::size_t i = 0; i < n; ++i) {
        unsigned long c = seed028_get_color(idx[i]);
        std::cout << "idx=" << idx[i]
                  << " color=0x" << std::hex << c << std::dec << "\n";
    }
}

unsigned long maxc(unsigned long arr[], std::size_t n) { // NC
    unsigned long m = 0;
    for (std::size_t i = 0; i < n; ++i)
        if (arr[i] > m) m = arr[i];
    return m;
}

} // namespace led_nc

int main() {
    using namespace led_nc;
    int idx[4] = {0,0,0,0};
    cycle(idx,4);
    unsigned long vals[3] = {0xFF0000,0x00FF00,0x0000FF};
    std::cout << "max=0x" << std::hex << maxc(vals,3) << std::dec << "\n";
    return 0;
}
