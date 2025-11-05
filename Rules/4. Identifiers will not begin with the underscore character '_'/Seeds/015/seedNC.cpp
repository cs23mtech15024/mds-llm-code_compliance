// Context: Pressure sensor scaling function

// Seed 015 — NC: function and parameters start with underscore
#include <iostream>
float _scale_pressure(float _raw, float _factor) { // NC
    return _raw * _factor;
}
int main(){
    std::cout << "pressure=" << _scale_pressure(1023.0F, 0.1F) << "\n";
    return 0;
}