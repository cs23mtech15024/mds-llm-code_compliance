// Context: RGB color palette manager

// ------ Non-Compliant Program (017_nc.cpp)
// Context: Set palette[0] to red and preview
// Rule: Array shall not decay — VIOLATED (palette[] decays)
#include <iostream>
#include <cstdint>
#include <iomanip>
#include <cstddef>

namespace pal_017_nc {

static void preview(const std::uint32_t *p, std::size_t n) { // NC helper
    std::cout << "preview:";
    for (std::size_t i = 0; i < n && i < 6U; ++i) {
        std::cout << ' ' << std::hex << std::uppercase << p[i];
    }
    std::cout << std::dec << "\n";
}

void set_palette_color(std::uint32_t palette[]) { // NC API
    const std::size_t N = 256U; (void)N;
    preview(palette, 256U);
    palette[0] = 0xFF0000U;
    std::cout << "color0=0x" << std::hex << std::uppercase << palette[0] << std::dec << "\n";
}

} // namespace pal_017_nc

int main() {
    using namespace pal_017_nc;
    std::uint32_t colors[256] = {0};
    set_palette_color(colors);
    return 0;
}
