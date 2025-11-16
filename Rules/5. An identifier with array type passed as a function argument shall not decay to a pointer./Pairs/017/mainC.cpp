// Context: RGB color palette manager

// ------ Compliant Program (017_c.cpp)
// Context: Set palette[0] to red and preview
// Rule: COMPLIANT (array by reference)
#include <iostream>
#include <cstdint>
#include <iomanip>
#include <cstddef>

namespace pal_017_c {

static void preview(const std::uint32_t (&p)[256]) { // C helper
    std::cout << "preview:";
    for (std::size_t i = 0; i < 6U; ++i) {
        std::cout << ' ' << std::hex << std::uppercase << p[i];
    }
    std::cout << std::dec << "\n";
}

void set_palette_color(std::uint32_t (&palette)[256]) { // C API
    preview(palette);
    palette[0] = 0xFF0000U;
    std::cout << "color0=0x" << std::hex << std::uppercase << palette[0] << std::dec << "\n";
}

} // namespace pal_017_c

int main() {
    using namespace pal_017_c;
    std::uint32_t colors[256] = {0};
    set_palette_color(colors);
    return 0;
}
