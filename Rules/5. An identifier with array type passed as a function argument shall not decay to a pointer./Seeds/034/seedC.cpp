// Context: Relay control state register

// Seed 034 — C: relay states by reference
#include <iostream>
#include <cstdint>
void activate_relays(std::uint8_t (&states)[16]) { // C
    states[0] = 0x0F;
    std::cout << "relay_bank0=0x" << std::hex << static_cast<int>(states[0]) << "\n";
}
int main(){
    std::uint8_t relay_states[16] = {0};
    activate_relays(relay_states);
    return 0;
}