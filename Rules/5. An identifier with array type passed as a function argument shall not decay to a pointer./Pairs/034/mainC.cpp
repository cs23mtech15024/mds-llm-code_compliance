// Context: Relay control state register

// ------ Compliant Program (034_c.cpp)
// Context: Set low nibble in relay bank 0, echo state
// Status: Array passed by reference (COMPLIANT)
#include <iostream>
#include <cstdint>
#include <iomanip>

namespace relay_034_c {

static void set_low_nibble(std::uint8_t (&reg)[16]) {
    reg[0] = static_cast<std::uint8_t>((reg[0] & 0xF0U) | 0x0FU);
}

void activate_relays(std::uint8_t (&states)[16]) { // C API
    set_low_nibble(states);
    std::cout << "relay_bank0=0x" << std::hex << std::uppercase << static_cast<int>(states[0]) << "\n";
}

} // namespace relay_034_c

int main() {
    using namespace relay_034_c;
    std::uint8_t relay_states[16] = {0xA0U};
    activate_relays(relay_states);
    return 0;
}
