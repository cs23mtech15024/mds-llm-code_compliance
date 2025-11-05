// Context: Temperature conversion utility

// Seed 008 — C: function and parameter without underscore prefix
#include <iostream>
float celsius_to_fahrenheit(float c) { // C
    return c * 9.0F / 5.0F + 32.0F;
}
int main(){
    std::cout << "temp=" << celsius_to_fahrenheit(25.0F) << "\n";
    return 0;
}