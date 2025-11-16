// Context: Relay control state register

// ------ Non-Compliant Program (034_nc.cpp)
// Context: Set low nibble in relay bank 0, echo state
// Rule: Array parameter decays to pointer (VIOLATION)
#include <iostream>
#include <cstdint>
#include <cstddef>
#include <iomanip>

namespace relay_034_nc {

static void set_low_nibble(std::uint8_t *reg, std::size_t n) {
    if (n > 0U) reg[0] = static_cast<std::uint8_t>((reg[0] & 0xF0U) | 0x0FU);
}

void activate_relays(std::uint8_t states[]) { // NC API
    const std::size_t BANKS = 16U; (void)BANKS;
    set_low_nibble(states, 16U);
    std::cout << "relay_bank0=0x" << std::hex << std::uppercase << static_cast<int>(states[0]) << "\n";
}

} // namespace relay_034_nc

int main() {
    using namespace relay_034_nc;
    std::uint8_t relay_states[16] = {0xA0U};
    activate_relays(relay_states);
    return 0;
}
