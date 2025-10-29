// Context: Camera Bayer pattern ratio helper

// Seed 013 — C: uppercase hex ratio
#include <iostream>
int main(){
    float ratio = static_cast<float>(0xA)/static_cast<float>(0x28); // C
    std::cout << "bayer_ratio=" << ratio << "\n";
    return 0;
}