// Context: Exponential moving average

// Seed 052 — NC: function and parameters start with underscore
#include <iostream>
float _ema_update(float _prev, float _new_val, float _alpha) { // NC
    return _alpha * _new_val + (1.0F - _alpha) * _prev;
}
int main(){
    std::cout << "ema=" << _ema_update(100.0F, 105.0F, 0.2F) << "\n";
    return 0;
}