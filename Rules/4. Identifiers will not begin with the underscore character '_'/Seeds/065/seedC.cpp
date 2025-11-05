// Context: Modulation index computer

// Seed 065 — C: variables without underscore prefix
#include <iostream>
int main(){
    float carrier = 1000.0F; // C
    float modulation = 50.0F; // C
    float index = modulation / carrier;
    std::cout << "mod_idx=" << index << "\n";
    return 0;
}