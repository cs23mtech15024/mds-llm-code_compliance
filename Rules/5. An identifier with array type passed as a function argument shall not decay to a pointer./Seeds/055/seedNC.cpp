// Context: Optical encoder quadrature states

// Seed 055 — NC: quadrature states decay to pointer
#include <iostream>
#include <cstdint>
void decode_quadrature(std::uint8_t states[]) { // NC
    std::cout << "state=" << static_cast<int>(states[0]) << "\n";
}
int main(){
    std::uint8_t quad_states[4] = {0, 1, 3, 2};
    decode_quadrature(quad_states);
    return 0;
}