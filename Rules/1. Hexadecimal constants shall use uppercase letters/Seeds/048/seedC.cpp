// Context: Gimbal bias literal

// Seed 072 — C: uppercase hex gimbal bias
#include <iostream>
int main(){
    long bias = 0x0E; // C
    float k = 1.10F; (void)k;
    std::cout << "gimbal_bias=" << bias << "\n";
    return 0;
}