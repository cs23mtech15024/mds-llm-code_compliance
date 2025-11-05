// Context: Color space RGB to HSV

// Seed 047 — C: function parameters without underscore prefix
#include <iostream>
void rgb_to_hsv(int r, int g, int b) { // C
    int max_val = (r > g) ? (r > b ? r : b) : (g > b ? g : b);
    std::cout << "max=" << max_val << "\n";
}
int main(){
    rgb_to_hsv(255, 128, 64);
    return 0;
}