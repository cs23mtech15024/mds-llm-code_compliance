// Context: Angle conversion degrees to radians

// Seed 028 — NC: function and parameter start with underscore
#include <iostream>
float _deg_to_rad(float _degrees) { // NC
    return _degrees * 0.0174533F;
}
int main(){
    std::cout << "rad=" << _deg_to_rad(90.0F) << "\n";
    return 0;
}