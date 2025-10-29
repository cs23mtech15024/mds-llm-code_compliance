// Context: Camera Bayer pattern ratio helper

// Seed 013 — NC: lowercase hex ratio
#include <iostream>
int main(){
    // 0xA/0x28 = 10/40 = 0.25
    float ratio = static_cast<float>(0xa)/static_cast<float>(0x28); // NC
    std::cout << "bayer_ratio=" << ratio << "\n";
    return 0;
}