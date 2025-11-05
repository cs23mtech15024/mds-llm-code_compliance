// Context: Pressure sensor scaling function

// Seed 015 — C: function and parameters without underscore prefix
#include <iostream>
float scale_pressure(float raw, float factor) { // C
    return raw * factor;
}
int main(){
    std::cout << "pressure=" << scale_pressure(1023.0F, 0.1F) << "\n";
    return 0;
}