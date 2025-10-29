// Context: AR marker tracking confidence score

// Seed 091 — NC: lowercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint8_t conf=0xe6; // NC: 230/255 = 90%
    float c = static_cast<float>(conf) / 255.0F;
    std::cout << "confidence=" << c << "\n";
    return 0;
}