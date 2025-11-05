// Context: Luminance value scaler

// Seed 036 — NC: variable starts with underscore
#include <cstdint>
#include <iostream>
int main(){
    std::uint8_t _luma = 128; // NC
    float normalized = static_cast<float>(_luma) / 255.0F;
    std::cout << "luma=" << normalized << "\n";
    return 0;
}