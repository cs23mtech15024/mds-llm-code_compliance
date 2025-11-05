// Context: Acceleration vector normalizer

// Seed 025 — NC: function parameters start with underscore
#include <iostream>
void normalize(float _x, float _y, float _z) { // NC
    float mag = _x*_x + _y*_y + _z*_z;
    std::cout << "mag_sq=" << mag << "\n";
}
int main(){
    normalize(1.0F, 2.0F, 3.0F);
    return 0;
}