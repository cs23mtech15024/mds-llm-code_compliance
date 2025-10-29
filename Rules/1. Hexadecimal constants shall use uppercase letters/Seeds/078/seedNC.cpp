// Context: WebRTC STUN server binding timeout

// Seed 090 — NC: lowercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint16_t timeout=0x1f4; // NC: 500ms
    std::cout << "stun_timeout=" << timeout << "\n";
    return 0;
}