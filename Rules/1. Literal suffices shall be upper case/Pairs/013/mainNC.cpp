// ------ Non-Compliant (Seed 013)
// Context: PWM duty cycle control simulation using lowercase float suffixes.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.

#include <iostream>
#include <vector>
#include <iomanip>

class PWMController {
    float dutyCycle;
    float frequency;
public:
    PWMController(float duty, float freq) : dutyCycle(duty), frequency(freq) {}
    void simulate() const {
        std::cout << "Simulating PWM at " << frequency << "Hz with "
                  << dutyCycle * 100.0f << "% duty cycle.\n";
    }
    void sweep() const {
        for (float d = 0.1f; d <= 0.9f; d += 0.2f) {
            std::cout << std::fixed << std::setprecision(1)
                      << "Duty: " << d * 100.0f << "%\n";
        }
    }
};

int main() {
    PWMController motor(0.25f, 1000.0f);
    motor.simulate();
    motor.sweep();
    return 0;
}