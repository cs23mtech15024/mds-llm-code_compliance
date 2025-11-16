// Context: Motor control PWM duty cycles

// Seed 006 — C: duty cycle array by reference
#include <iostream>
void set_pwm_values(int (&duty_cycles)[8]) { // C
    duty_cycles[0] = 75;
    std::cout << "pwm0=" << duty_cycles[0] << "\n";
}
int main(){
    int pwm_channels[8] = {0};
    set_pwm_values(pwm_channels);
    return 0;
}