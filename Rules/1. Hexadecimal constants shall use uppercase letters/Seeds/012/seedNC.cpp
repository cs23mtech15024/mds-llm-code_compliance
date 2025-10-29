// Context: Kinematics logger tag for motion frames

// Seed 014 — NC: lowercase hex frame tag
#include <cstdint>
#include <iostream>
int main(){
    std::uint8_t tag=0x9e; // NC
    float v=3.2F, t=2.0F;
    std::cout << "v*t=" << v*t << " tag=0x" << std::hex << static_cast<unsigned>(tag) << "\n";
    return 0;
}