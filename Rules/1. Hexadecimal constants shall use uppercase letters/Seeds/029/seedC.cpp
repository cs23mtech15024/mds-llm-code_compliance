// Context: mDNS port literal tag

// Seed 042 — C: uppercase hex in mDNS port
#include <iostream>
int main(){
    unsigned mdnsPort=0x14E9; // C
    std::cout << "mdns_port=0x" << std::hex << mdnsPort << "\n";
    return 0;
}