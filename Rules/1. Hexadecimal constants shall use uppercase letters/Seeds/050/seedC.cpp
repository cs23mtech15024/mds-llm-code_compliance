// Context: Antenna epoch literal

// Seed 074 — C: uppercase hex epoch
#include <iostream>
int main(){
    long epoch = 0x7E1; // C
    float refine = 0.005F; (void)refine;
    std::cout << "epoch=0x" << std::hex << epoch << "\n";
    return 0;
}