// Context: Medical ventilator flow estimator

// ------ Non-Compliant Program (003_nc.cpp)
// Context: Medical ventilator flow estimator
// MISRA C++ 8-0-1 violations: multiple declarators per declaration
#include <iostream>
#include <iomanip>
#include <array>
#include <cstddef>
#include <cmath>

namespace ctrl_003 {
    struct ControlState {
        float output;
        float derivative;
    }; // OK: struct members allowed
    
    static float clamp(float value, float min_val, float max_val) {
        if (value < min_val) return min_val;
        if (value > max_val) return max_val;
        return value;
    }
    
    static float compute_pid(float error, float kp, float ki, float kd,
                            float integral, float derivative) {
        return (kp * error) + (ki * integral) + (kd * derivative);
    }
    
    void execute() {
        double flow=0.0, pressure=0.0;        // NC
        long alarms=0L, warnings=0L;        // NC
        bool humidOn=false, heaterOn=false;        // NC
        ControlState state{0.0F, 0.0F};
        const float dt = 0.01F;
        const float target_value = 10.0F;
        std::array<float,12U> setpoints{
            9.0F, 9.5F, 10.0F, 10.5F, 11.0F, 10.5F,
            10.0F, 9.5F, 9.0F, 9.5F, 10.0F, 10.5F
        };
        
        float integral = 0.0F;
        float prev_error = 0.0F;
        
        for (std::size_t i = 0U; i < setpoints.size(); ++i) {
            float reference = setpoints[i];
            float error = reference - state.output;
            integral += error * dt;
            float derivative = (error - prev_error) / dt;
            prev_error = error;
            
            float control = compute_pid(error, 1.0F, 0.1F, 0.05F, 
                                       integral, derivative);
            control = clamp(control, -5.0F, 5.0F);
            
            state.output += control * dt;
            state.derivative = derivative;
            
            if ((i % 3U) == 0U) {
                std::cout << "step=" << i
                         << " ref=" << std::fixed << std::setprecision(2) << reference
                         << " out=" << state.output
                         << " err=" << error
                         << " ctrl=" << control
                         << std::endl;
            }
        }
        
        std::cout << "Control loop completed. Final output=" << state.output << std::endl;
    }
}

int main() {
    ctrl_003::execute();
    return 0;
}
