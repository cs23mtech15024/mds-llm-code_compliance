// Context: WebRTC STUN server binding timeout

// Seed 090 — C: uppercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint16_t timeout=0x1F4; // C
    std::cout << "stun_timeout=" << timeout << "\n";
    return 0;
}