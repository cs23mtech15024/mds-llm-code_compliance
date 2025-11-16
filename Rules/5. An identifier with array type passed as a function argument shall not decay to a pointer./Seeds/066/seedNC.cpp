// Context: USB endpoint buffer descriptors

// Seed 066 — NC: descriptors decay to pointer
#include <iostream>
#include <cstdint>
void configure_endpoints(std::uint32_t descriptors[]) { // NC
    descriptors[0] = 0x80;
    std::cout << "ep0=0x" << std::hex << descriptors[0] << "\n";
}
int main(){
    std::uint32_t usb_eps[8] = {0};
    configure_endpoints(usb_eps);
    return 0;
}