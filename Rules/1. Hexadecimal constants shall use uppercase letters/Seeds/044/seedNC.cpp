// Context: Turbine speed adjust literal

// Seed 067 — NC: lowercase hex speed adjust
#include <iostream>
int main(){
    long adjust = 0x1e; // NC: 30
    float gain = 2.0F; (void)gain;
    std::cout << "turbine_adj=" << adjust << "\n";
    return 0;
}