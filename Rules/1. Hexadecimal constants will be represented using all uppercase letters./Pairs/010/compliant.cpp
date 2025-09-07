// ------ Compliant
// Pair 10 — Seed: 1.0f -> 1.0F
// Context: PID control for motor speed in DRDO-controlled system.
// Violation: lowercase 'f' suffix.
// Source: MISRA C++ Rule 2-13-4 (literal suffixes shall be upper case).

#include <iostream>
#include <vector>
#include <iomanip>

class PIDController_C {
public:
    PIDController_C(float kp, float ki, float kd)
        : Kp(kp), Ki(ki), Kd(kd), prevError(0.0F), integral(0.0F) {} // C: 'F'

    float compute(float setpoint, float actual) {
        float error = setpoint - actual;
        integral += error * dt;
        float derivative = (error - prevError) / dt;
        float output = Kp * error + Ki * integral + Kd * derivative;
        prevError = error;
        return output;
    }

    void simulate() {
        float setpoint = 100.0F; // C
        float actual = 0.0F;
        for (int i = 0; i < 5; ++i) {
            float control = compute(setpoint, actual);
            actual += control * 0.1F; // C
            std::cout << "[C] Iter " << i << ": actual=" << std::fixed
                      << std::setprecision(2) << actual << "\n";
        }
    }

private:
    float Kp, Ki, Kd;
    float prevError;
    float integral;
    static constexpr float dt = 1.0F; // C
};

int main() {
    PIDController_C pid(1.0F, 0.1F, 0.05F); // C
    pid.simulate();
    return 0;
}