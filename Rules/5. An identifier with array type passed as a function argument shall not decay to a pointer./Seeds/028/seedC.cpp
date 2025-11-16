// Context: Thermocouple lookup table

// Seed 028 — C: lookup table by reference
#include <iostream>
float lookup_temperature(float (&table)[256]) { // C
    return table[0];
}
int main(){
    float thermocouple_lut[256] = {25.0F};
    std::cout << "temp=" << lookup_temperature(thermocouple_lut) << "\n";
    return 0;
}