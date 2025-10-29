// Context: GPS precision normalization cap

// Seed 031 — NC: lowercase hex cap used in normalization
#include <iostream>
int main(){
    const unsigned MAX_POINTS=0x3e8; // NC: 1000
    double deg2rad=0.01745;
    std::cout << "cap=" << std::hex << MAX_POINTS << " ratio=" << deg2rad << "\n";
    return 0;
}