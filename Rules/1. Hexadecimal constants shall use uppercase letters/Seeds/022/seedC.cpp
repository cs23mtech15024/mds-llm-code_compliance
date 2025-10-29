// Context: GPS precision normalization cap

// Seed 031 — C: uppercase hex cap used in normalization
#include <iostream>
int main(){
    const unsigned MAX_POINTS=0x3E8; // C
    double deg2rad=0.01745;
    std::cout << "cap=" << std::hex << MAX_POINTS << " ratio=" << deg2rad << "\n";
    return 0;
}