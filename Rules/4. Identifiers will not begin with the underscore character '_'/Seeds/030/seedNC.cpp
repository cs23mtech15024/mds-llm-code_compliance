// Context: Gain coefficient adjuster

// Seed 030 — NC: variable starts with underscore
#include <iostream>
int main(){
    float _gain = 1.5F; // NC
    float signal = 100.0F;
    std::cout << "output=" << signal * _gain << "\n";
    return 0;
}