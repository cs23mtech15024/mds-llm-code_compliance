// Context: LED matrix display buffer

// ------ Compliant Program (010_c.cpp)
// Context: LED matrix display buffer
// C: led_matrix accepted by reference; helper uses array ref
#include <iostream>
#include <cstdint>
#include <cstddef>
#include <iomanip>

namespace led_010_c {

template <std::size_t N>
static void set_row(std::uint8_t (&buf)[N], std::uint8_t v) { // C
    if (N > 0U) { buf[0] = v; }
}

void update_display(std::uint8_t (&led_matrix)[64]) { // C (fixed size per seed)
    set_row(led_matrix, 0xFFU);
    std::cout << "led_row0=0x" << std::hex << static_cast<int>(led_matrix[0]) << "\n";
}

} // namespace led_010_c

int main() {
    using namespace led_010_c;
    std::uint8_t display[64] = {0};
    update_display(display);
    return 0;
}
