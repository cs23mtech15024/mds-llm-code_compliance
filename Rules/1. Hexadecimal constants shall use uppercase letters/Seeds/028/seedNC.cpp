// Context: PWM duty-cycle mask for timer

// Seed 038 — NC: lowercase hex pwm mask
#include <iostream>
int main(){
    unsigned pwmMask=0xff; // NC
    float dutyMin=0.05F, dutyMax=0.95F; (void)dutyMin; (void)dutyMax;
    std::cout << "pwm_mask=0x" << std::hex << pwmMask << "\n";
    return 0;
}