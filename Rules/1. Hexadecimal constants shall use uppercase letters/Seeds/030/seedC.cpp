// Context: Vehicle samplerate literal tag

// Seed 044 — C: uppercase hex in sample rate
#include <iostream>
int main(){
    unsigned hz=0x6E; // C
    std::cout << "veh_samplerate=" << std::dec << hz << "\n";
    return 0;
}