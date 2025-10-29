// Context: PWM duty-cycle mask for timer

// Seed 038 — C: uppercase hex pwm mask
#include <iostream>
int main(){
    unsigned pwmMask=0xFF; // C
    float dutyMin=0.05F, dutyMax=0.95F; (void)dutyMin; (void)dutyMax;
    std::cout << "pwm_mask=0x" << std::hex << pwmMask << "\n";
    return 0;
}