// Context: Antenna epoch literal

// Seed 074 — NC: lowercase hex epoch
#include <iostream>
int main(){
    long epoch = 0x7e1; // NC: 2017
    float refine = 0.005F; (void)refine;
    std::cout << "epoch=0x" << std::hex << epoch << "\n";
    return 0;
}