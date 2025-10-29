// Context: Speech recognition phoneme probability threshold

// Seed 083 — NC: lowercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint8_t thresh=0xcc; // NC: 204/255 = 80%
    float p = static_cast<float>(thresh) / 255.0F;
    std::cout << "thresh=" << p << "\n";
    return 0;
}