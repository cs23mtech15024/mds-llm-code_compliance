// Context: Altitude compensation factor

// Seed 022 — NC: variable starts with underscore
#include <iostream>
int main(){
    float _altitude_m = 1500.0F; // NC
    float compensation = 1.0F - (_altitude_m / 10000.0F);
    std::cout << "comp=" << compensation << "\n";
    return 0;
}