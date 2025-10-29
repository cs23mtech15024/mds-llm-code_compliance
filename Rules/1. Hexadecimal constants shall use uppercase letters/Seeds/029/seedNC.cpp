// Context: mDNS port literal tag

// Seed 042 — NC: lowercase hex in mDNS port
#include <iostream>
int main(){
    unsigned mdnsPort=0x14e9; // NC: 5353
    std::cout << "mdns_port=0x" << std::hex << mdnsPort << "\n";
    return 0;
}