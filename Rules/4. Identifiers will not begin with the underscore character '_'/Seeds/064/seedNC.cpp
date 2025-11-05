// Context: Slew rate limit calculator

// Seed 064 — NC: function starts with underscore
#include <iostream>
float _calc_slew_rate(float delta, float time) { // NC
    return delta / time;
}
int main(){
    std::cout << "slew=" << _calc_slew_rate(10.0F, 0.1F) << "\n";
    return 0;
}