// Context: Gimbal bias literal

// Seed 072 — NC: lowercase hex gimbal bias
#include <iostream>
int main(){
    long bias = 0x0e; // NC: 14
    float k = 1.10F; (void)k;
    std::cout << "gimbal_bias=" << bias << "\n";
    return 0;
}