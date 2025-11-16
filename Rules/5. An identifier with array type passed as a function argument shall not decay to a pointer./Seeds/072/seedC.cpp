// Context: Thermal camera pixel matrix

// Seed 072 — C: thermal pixels by reference
#include <iostream>
float get_max_temperature(float (&pixels)[4096]) { // C
    return pixels[0];
}
int main(){
    float thermal_image[4096] = {25.5F};
    std::cout << "max_temp=" << get_max_temperature(thermal_image) << "\n";
    return 0;
}