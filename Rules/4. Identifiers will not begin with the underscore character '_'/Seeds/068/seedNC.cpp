// Context: Quantization step calculator

// Seed 068 — NC: function and parameter start with underscore
#include <iostream>
float _calc_q_step(int _bits) { // NC
    return 1.0F / (1 << _bits);
}
int main(){
    std::cout << "q_step=" << _calc_q_step(8) << "\n";
    return 0;
}