// Context: Angle conversion degrees to radians

// Seed 028 — C: function and parameter without underscore prefix
#include <iostream>
float deg_to_rad(float degrees) { // C
    return degrees * 0.0174533F;
}
int main(){
    std::cout << "rad=" << deg_to_rad(90.0F) << "\n";
    return 0;
}