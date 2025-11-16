// Context: Relay control state register

// Seed 034 — NC: relay states decay to pointer
#include <iostream>
#include <cstdint>
void activate_relays(std::uint8_t states[]) { // NC
    states[0] = 0x0F;
    std::cout << "relay_bank0=0x" << std::hex << static_cast<int>(states[0]) << "\n";
}
int main(){
    std::uint8_t relay_states[16] = {0};
    activate_relays(relay_states);
    return 0;
}