// Context: Battery sim step-count literal tag

// Seed 045 — C: uppercase hex in step count
#include <iostream>
int main(){
    unsigned steps=0x0A; // C
    std::cout << "sim_steps=" << steps << "\n";
    return 0;
}