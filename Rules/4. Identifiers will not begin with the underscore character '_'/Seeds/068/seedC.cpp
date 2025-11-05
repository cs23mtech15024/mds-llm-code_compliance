// Context: Quantization step calculator

// Seed 068 — C: function and parameter without underscore prefix
#include <iostream>
float calc_q_step(int bits) { // C
    return 1.0F / (1 << bits);
}
int main(){
    std::cout << "q_step=" << calc_q_step(8) << "\n";
    return 0;
}