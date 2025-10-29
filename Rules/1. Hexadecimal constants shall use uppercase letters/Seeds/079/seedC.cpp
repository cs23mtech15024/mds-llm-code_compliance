// Context: AR marker tracking confidence score

// Seed 091 — C: uppercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint8_t conf=0xE6; // C
    float c = static_cast<float>(conf) / 255.0F;
    std::cout << "confidence=" << c << "\n";
    return 0;
}