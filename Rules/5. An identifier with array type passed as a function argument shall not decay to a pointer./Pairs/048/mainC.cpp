// Context: Capacitive touch button states

// ------ Compliant Program (048_c.cpp)
// Context: Check if first touch button is pressed, also count actives
// Status: Array passed by reference (COMPLIANT)
#include <iostream>
#include <cstdint>

namespace touch_048_c {

static std::size_t count(const std::uint8_t (&b)[12]) {
    std::size_t c = 0U; for (std::size_t i = 0; i < 12U; ++i) if (b[i]) ++c; return c;
}

bool is_button_pressed(std::uint8_t (&buttons)[12]) { // C API
    const auto active = count(buttons);
    std::cout << "active=" << active << "\n";
    return buttons[0] != 0U;
}

} // namespace touch_048_c

int main() {
    using namespace touch_048_c;
    std::uint8_t touch_buttons[12] = {1, 0, 0};
    std::cout << std::boolalpha << "btn0=" << is_button_pressed(touch_buttons) << "\n";
    return 0;
}
