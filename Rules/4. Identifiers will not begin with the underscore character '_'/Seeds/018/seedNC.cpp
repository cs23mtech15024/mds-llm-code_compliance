// Context: PWM duty cycle calculator

// Seed 018 — NC: function starts with underscore
#include <iostream>
int _calc_duty_cycle(float percent) { // NC
    return static_cast<int>(percent * 255.0F / 100.0F);
}
int main(){
    std::cout << "duty=" << _calc_duty_cycle(75.0F) << "\n";
    return 0;
}