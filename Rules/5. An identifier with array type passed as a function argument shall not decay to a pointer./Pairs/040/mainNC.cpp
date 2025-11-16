// Context: OLED display framebuffer

// ------ Non-Compliant Program (040_nc.cpp)
// Context: Clear first byte of a 1KB OLED framebuffer, echo state
// Rule: Array parameter decays to pointer (VIOLATION)
#include <iostream>
#include <cstdint>
#include <cstddef>
#include <iomanip>

namespace oled_040_nc {

static void clear_head(std::uint8_t *fb, std::size_t n) { if (n) fb[0] = 0x00U; }

void clear_screen(std::uint8_t framebuffer[]) { // NC API
    clear_head(framebuffer, 1024U);
    std::cout << "fb0=0x" << std::hex << std::uppercase << static_cast<int>(framebuffer[0]) << "\n";
}

} // namespace oled_040_nc

int main() {
    using namespace oled_040_nc;
    std::uint8_t oled_fb[1024] = {0xFF};
    clear_screen(oled_fb);
    return 0;
}
