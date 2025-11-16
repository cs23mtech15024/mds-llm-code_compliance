// Context: Digital potentiometer tap settings

// Seed 068 — NC: tap settings decay to pointer
#include <iostream>
#include <cstdint>
void set_pot_values(std::uint8_t taps[]) { // NC
    taps[0] = 128;
    std::cout << "pot0=" << static_cast<int>(taps[0]) << "\n";
}
int main(){
    std::uint8_t digipot_taps[4] = {0};
    set_pot_values(digipot_taps);
    return 0;
}