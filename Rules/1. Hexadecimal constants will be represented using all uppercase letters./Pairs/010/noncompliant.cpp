// ------ Non-Compliant
// Pair 10 — Seed: 1.0f -> 1.0F
// Context: PID control for motor speed in DRDO-controlled system.
// Violation: lowercase 'f' suffix.
// Source: MISRA C++ Rule 2-13-4 (literal suffixes shall be upper case).

#include <iostream>
#include <vector>
#include <iomanip>

class PIDController_NC {
public:
    PIDController_NC(float kp, float ki, float kd)
        : Kp(kp), Ki(ki), Kd(kd), prevError(0.0f), integral(0.0f) {} // NC: 'f'

    float compute(float setpoint, float actual) {
        float error = setpoint - actual;
        integral += error * dt;
        float derivative = (error - prevError) / dt;
        float output = Kp * error + Ki * integral + Kd * derivative;
        prevError = error;
        return output;
    }

    void simulate() {
        float setpoint = 100.0f; // NC
        float actual = 0.0f;
        for (int i = 0; i < 5; ++i) {
            float control = compute(setpoint, actual);
            actual += control * 0.1f; // NC
            std::cout << "[NC] Iter " << i << ": actual=" << std::fixed
                      << std::setprecision(2) << actual << "\n";
        }
    }

private:
    float Kp, Ki, Kd;
    float prevError;
    float integral;
    static constexpr float dt = 1.0f; // NC
};

int main() {
    PIDController_NC pid(1.0f, 0.1f, 0.05f); // NC
    pid.simulate();
    return 0;
}