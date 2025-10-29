// Context: Ballast reference-depth literal

// Seed 064 — C: uppercase hex ballast depth
#include <iostream>
int main(){
    long refDepth = 0x1A0; // C
    float factor = 1.5F; (void)factor;
    std::cout << "ref_depth=0x" << std::hex << refDepth << "\n";
    return 0;
}