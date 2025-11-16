// Context: Thermal camera pixel matrix

// Seed 072 — NC: thermal pixels decay to pointer
#include <iostream>
float get_max_temperature(float pixels[]) { // NC
    return pixels[0];
}
int main(){
    float thermal_image[4096] = {25.5F};
    std::cout << "max_temp=" << get_max_temperature(thermal_image) << "\n";
    return 0;
}