// Context: Modulation index computer

// Seed 065 — NC: variables start with underscore
#include <iostream>
int main(){
    float _carrier = 1000.0F; // NC
    float _modulation = 50.0F; // NC
    float index = _modulation / _carrier;
    std::cout << "mod_idx=" << index << "\n";
    return 0;
}