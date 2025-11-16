// Context: DAC output voltage levels

// Seed 031 — NC: DAC values decay to pointer
#include <iostream>
#include <cstdint>
void set_dac_outputs(std::uint16_t values[]) { // NC
    values[0] = 2048;
    std::cout << "dac0=" << values[0] << "\n";
}
int main(){
    std::uint16_t dac_channels[4] = {0};
    set_dac_outputs(dac_channels);
    return 0;
}