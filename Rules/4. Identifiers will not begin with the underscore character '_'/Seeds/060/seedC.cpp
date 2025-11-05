// Context: Bandwidth limiter function

// Seed 060 — C: function and parameter without underscore prefix
#include <iostream>
float limit_bandwidth(float value, float max_bw) { // C
    return value > max_bw ? max_bw : value;
}
int main(){
    std::cout << "bw=" << limit_bandwidth(150.0F, 100.0F) << "\n";
    return 0;
}