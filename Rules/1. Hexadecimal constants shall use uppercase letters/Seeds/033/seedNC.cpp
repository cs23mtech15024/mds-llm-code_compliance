// Context: Charging seconds literal tag (BMS)

// Seed 048 — NC: lowercase hex in seconds tag
#include <iostream>
int main(){
    long secs=0x0e10; // NC: 3600
    std::cout << "charge_secs=0x" << std::hex << secs << "\n";
    return 0;
}