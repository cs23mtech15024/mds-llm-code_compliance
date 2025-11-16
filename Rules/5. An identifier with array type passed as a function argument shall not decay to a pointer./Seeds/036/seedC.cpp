// Context: Infrared sensor zone detection

// Seed 036 — C: IR zone data by reference
#include <iostream>
#include <cstdint>
bool check_zones(std::uint8_t (&zones)[8]) { // C
    return zones[0] > 0;
}
int main(){
    std::uint8_t ir_zones[8] = {1, 0, 1};
    std::cout << "zone0_active=" << check_zones(ir_zones) << "\n";
    return 0;
}