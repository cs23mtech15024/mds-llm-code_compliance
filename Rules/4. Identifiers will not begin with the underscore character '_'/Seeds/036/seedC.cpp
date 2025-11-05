// Context: Luminance value scaler

// Seed 036 — C: variable without underscore prefix
#include <cstdint>
#include <iostream>
int main(){
    std::uint8_t luma = 128; // C
    float normalized = static_cast<float>(luma) / 255.0F;
    std::cout << "luma=" << normalized << "\n";
    return 0;
}