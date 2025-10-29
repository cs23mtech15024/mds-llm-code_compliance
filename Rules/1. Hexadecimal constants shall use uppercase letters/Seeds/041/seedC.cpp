// Context: Steering bias literal

// Seed 063 — C: uppercase hex steering bias
#include <iostream>
int main(){
    long bias = 0x0D; // C
    float s = 0.9F; (void)s;
    std::cout << "steer_bias=" << std::dec << bias << "\n";
    return 0;
}