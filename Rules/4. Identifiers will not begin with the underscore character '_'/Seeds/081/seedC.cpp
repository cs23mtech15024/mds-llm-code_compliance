// Context: Error accumulator variable

// Seed 081 — C: variable without underscore prefix
#include <iostream>
int main(){
    float error_sum = 0.0F; // C
    error_sum += 0.5F;
    std::cout << "err_sum=" << error_sum << "\n";
    return 0;
}