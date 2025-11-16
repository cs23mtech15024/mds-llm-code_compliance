// Context: OLED display framebuffer

// ------ Compliant Program (040_c.cpp)
// Context: Clear first byte of a 1KB OLED framebuffer, echo state
// Status: Array passed by reference (COMPLIANT)
#include <iostream>
#include <cstdint>
#include <iomanip>

namespace oled_040_c {

static void clear_head(std::uint8_t (&fb)[1024]) { fb[0] = 0x00U; }

void clear_screen(std::uint8_t (&framebuffer)[1024]) { // C API
    clear_head(framebuffer);
    std::cout << "fb0=0x" << std::hex << std::uppercase << static_cast<int>(framebuffer[0]) << "\n";
}

} // namespace oled_040_c

int main() {
    using namespace oled_040_c;
    std::uint8_t oled_fb[1024] = {0xFF};
    clear_screen(oled_fb);
    return 0;
}
