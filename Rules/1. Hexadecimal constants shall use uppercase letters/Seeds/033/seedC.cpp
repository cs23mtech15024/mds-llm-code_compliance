// Context: Charging seconds literal tag (BMS)

// Seed 048 — C: uppercase hex in seconds tag
#include <iostream>
int main(){
    long secs=0x0E10; // C
    std::cout << "charge_secs=0x" << std::hex << secs << "\n";
    return 0;
}