// Context: Vehicle samplerate literal tag

// Seed 044 — NC: lowercase hex in sample rate
#include <iostream>
int main(){
    unsigned hz=0x6e; // NC: 110
    std::cout << "veh_samplerate=" << std::dec << hz << "\n";
    return 0;
}