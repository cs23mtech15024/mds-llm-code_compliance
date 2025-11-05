// Context: Temperature conversion utility

// Seed 008 — NC: function and variable start with underscore
#include <iostream>
float _celsius_to_fahrenheit(float _c) { // NC: both function and parameter
    return _c * 9.0F / 5.0F + 32.0F;
}
int main(){
    std::cout << "temp=" << _celsius_to_fahrenheit(25.0F) << "\n";
    return 0;
}