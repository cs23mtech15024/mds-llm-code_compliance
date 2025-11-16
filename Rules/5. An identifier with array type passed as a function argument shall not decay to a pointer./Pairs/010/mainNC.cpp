// Context: LED matrix display buffer

// ------ Non-Compliant Program (010_nc.cpp)
// Context: LED matrix display buffer
// NC: led_matrix[] decays; helper uses pointer/length
#include <iostream>
#include <cstdint>
#include <cstddef>
#include <iomanip>

namespace led_010_nc {

static void set_row(std::uint8_t *buf, std::size_t n, std::uint8_t v) { // NC
    if (n > 0U) { buf[0] = v; }
}

void update_display(std::uint8_t led_matrix[]) { // NC
    const std::size_t N = 64U;
    set_row(led_matrix, N, 0xFFU);
    std::cout << "led_row0=0x" << std::hex << static_cast<int>(led_matrix[0]) << "\n";
}

} // namespace led_010_nc

int main() {
    using namespace led_010_nc;
    std::uint8_t display[64] = {0};
    update_display(display);
    return 0;
}
