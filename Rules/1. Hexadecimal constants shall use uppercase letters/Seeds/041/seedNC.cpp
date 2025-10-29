// Context: Steering bias literal

// Seed 063 — NC: lowercase hex steering bias
#include <iostream>
int main(){
    long bias = 0x0d; // NC: 13
    float s = 0.9F; (void)s;
    std::cout << "steer_bias=" << std::dec << bias << "\n";
    return 0;
}