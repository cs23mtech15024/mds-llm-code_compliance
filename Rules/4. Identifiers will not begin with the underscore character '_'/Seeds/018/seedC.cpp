// Context: PWM duty cycle calculator

// Seed 018 — C: function without underscore prefix
#include <iostream>
int calc_duty_cycle(float percent) { // C
    return static_cast<int>(percent * 255.0F / 100.0F);
}
int main(){
    std::cout << "duty=" << calc_duty_cycle(75.0F) << "\n";
    return 0;
}