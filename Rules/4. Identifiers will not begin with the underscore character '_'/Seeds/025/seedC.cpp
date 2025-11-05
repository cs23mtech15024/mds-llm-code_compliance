// Context: Acceleration vector normalizer

// Seed 025 — C: function parameters without underscore prefix
#include <iostream>
void normalize(float x, float y, float z) { // C
    float mag = x*x + y*y + z*z;
    std::cout << "mag_sq=" << mag << "\n";
}
int main(){
    normalize(1.0F, 2.0F, 3.0F);
    return 0;
}