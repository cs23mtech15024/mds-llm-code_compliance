// Context: Slew rate limit calculator

// Seed 064 — C: function without underscore prefix
#include <iostream>
float calc_slew_rate(float delta, float time) { // C
    return delta / time;
}
int main(){
    std::cout << "slew=" << calc_slew_rate(10.0F, 0.1F) << "\n";
    return 0;
}