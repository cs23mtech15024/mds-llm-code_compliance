// Context: Coordinate transform X-axis

// Seed 057 — C: function without underscore prefix
#include <iostream>
float transform_x(float x, float offset) { // C
    return x + offset;
}
int main(){
    std::cout << "x_new=" << transform_x(10.0F, 5.0F) << "\n";
    return 0;
}