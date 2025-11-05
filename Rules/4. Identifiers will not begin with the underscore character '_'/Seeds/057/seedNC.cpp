// Context: Coordinate transform X-axis

// Seed 057 — NC: function starts with underscore
#include <iostream>
float _transform_x(float x, float offset) { // NC
    return x + offset;
}
int main(){
    std::cout << "x_new=" << _transform_x(10.0F, 5.0F) << "\n";
    return 0;
}