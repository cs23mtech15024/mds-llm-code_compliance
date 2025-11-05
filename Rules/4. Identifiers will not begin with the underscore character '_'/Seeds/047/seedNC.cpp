// Context: Color space RGB to HSV

// Seed 047 — NC: function parameters start with underscore
#include <iostream>
void rgb_to_hsv(int _r, int _g, int _b) { // NC
    int max_val = (_r > _g) ? (_r > _b ? _r : _b) : (_g > _b ? _g : _b);
    std::cout << "max=" << max_val << "\n";
}
int main(){
    rgb_to_hsv(255, 128, 64);
    return 0;
}