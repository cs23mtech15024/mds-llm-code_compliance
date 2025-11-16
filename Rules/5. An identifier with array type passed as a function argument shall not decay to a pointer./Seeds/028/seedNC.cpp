// Context: Thermocouple lookup table

// Seed 028 — NC: lookup table decays to pointer
#include <iostream>
float lookup_temperature(float table[]) { // NC
    return table[0];
}
int main(){
    float thermocouple_lut[256] = {25.0F};
    std::cout << "temp=" << lookup_temperature(thermocouple_lut) << "\n";
    return 0;
}