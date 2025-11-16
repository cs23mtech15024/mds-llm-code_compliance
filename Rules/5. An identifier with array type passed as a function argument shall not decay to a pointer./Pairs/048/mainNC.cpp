// Context: Capacitive touch button states

// ------ Non-Compliant Program (048_nc.cpp)
// Context: Check if first touch button is pressed, also count actives
// Rule: Array parameter decays to pointer (VIOLATION)
#include <iostream>
#include <cstdint>
#include <cstddef>

namespace touch_048_nc {

// NC helper: takes pointer and runtime length
static std::size_t count(const std::uint8_t *b, std::size_t n) {
    std::size_t c = 0U; for (std::size_t i = 0; i < n; ++i) if (b[i]) ++c; return c;
}

bool is_button_pressed(std::uint8_t buttons[]) { // NC API
    const auto active = count(buttons, 12U);
    std::cout << "active=" << active << "\n";
    return buttons[0] != 0U;
}

} // namespace touch_048_nc

int main() {
    using namespace touch_048_nc;
    std::uint8_t touch_buttons[12] = {1, 0, 0};
    std::cout << std::boolalpha << "btn0=" << is_button_pressed(touch_buttons) << "\n";
    return 0;
}
