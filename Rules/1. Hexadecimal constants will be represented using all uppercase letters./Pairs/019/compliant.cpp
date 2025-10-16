// ------ Compliant
// Pair 19 — Seed: 0u -> 0U
// Context: State initialization for missile autopilot state machine.
// Violation: lowercase 'u' suffix.
// Source: MISRA C++ Rule 2-13-4 (literal suffixes shall be upper case).

#include <iostream>
#include <array>
#include <string>

enum class AutoState : unsigned {
    IDLE = 0U,
    ARM  = 1U,
    ENGAGE = 2U,
    ABORT = 3U
};

struct Telemetry {
    unsigned timestamp;
    float altitude;
    float speed;
};

class Autopilot_C {
public:
    Autopilot_C()
      : currentState(AutoState::IDLE),
        retryCount(0U),    // C seed usage: 0U
        errorFlag(0U)      // C
    {
        for (auto &t : history) t = {0U, 0.0F, 0.0F}; // C
    }

    void step() {
        // simple state-machine demonstration (no UB, deterministic)
        switch (currentState) {
            case AutoState::IDLE:
                std::cout << "[C] State: IDLE\n";
                // transition to ARM for demo
                currentState = AutoState::ARM;
                break;
            case AutoState::ARM:
                std::cout << "[C] State: ARM\n";
                currentState = AutoState::ENGAGE;
                break;
            case AutoState::ENGAGE:
                std::cout << "[C] State: ENGAGE\n";
                // simulate a retry increment
                ++retryCount;
                if (retryCount > 3U) currentState = AutoState::ABORT;
                break;
            case AutoState::ABORT:
                std::cout << "[C] State: ABORT\n";
                errorFlag = 1U;
                break;
        }
    }

    void logStatus() const {
        std::cout << "[C] retryCount=" << retryCount << ", errorFlag=" << errorFlag << "\n";
    }

private:
    AutoState currentState;
    unsigned retryCount;
    unsigned errorFlag;
    std::array<Telemetry, 8> history;
};

int main() {
    Autopilot_C ap;
    for (int i = 0; i < 6; ++i) {
        ap.step();
        ap.logStatus();
    }
    return 0;
}