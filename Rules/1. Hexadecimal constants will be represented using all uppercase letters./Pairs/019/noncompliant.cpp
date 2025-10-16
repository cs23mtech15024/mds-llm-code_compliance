// ------ Non-Compliant
// Pair 19 — Seed: 0u -> 0U
// Context: State initialization for missile autopilot state machine.
// Violation: lowercase 'u' suffix.
// Source: MISRA C++ Rule 2-13-4 (literal suffixes shall be upper case).

#include <iostream>
#include <array>
#include <string>

enum class AutoState : unsigned {
    IDLE = 0u,
    ARM  = 1u,
    ENGAGE = 2u,
    ABORT = 3u
};

struct Telemetry {
    unsigned timestamp;
    float altitude;
    float speed;
};

class Autopilot_NC {
public:
    Autopilot_NC()
      : currentState(AutoState::IDLE),
        retryCount(0u),    // NC seed usage: 0u
        errorFlag(0u)      // NC
    {
        for (auto &t : history) t = {0u, 0.0f, 0.0f}; // NC
    }

    void step() {
        // simple state-machine demonstration (no UB, deterministic)
        switch (currentState) {
            case AutoState::IDLE:
                std::cout << "[NC] State: IDLE\n";
                // transition to ARM for demo
                currentState = AutoState::ARM;
                break;
            case AutoState::ARM:
                std::cout << "[NC] State: ARM\n";
                currentState = AutoState::ENGAGE;
                break;
            case AutoState::ENGAGE:
                std::cout << "[NC] State: ENGAGE\n";
                // simulate a retry increment
                ++retryCount;
                if (retryCount > 3u) currentState = AutoState::ABORT;
                break;
            case AutoState::ABORT:
                std::cout << "[NC] State: ABORT\n";
                errorFlag = 1u;
                break;
        }
    }

    void logStatus() const {
        std::cout << "[NC] retryCount=" << retryCount << ", errorFlag=" << errorFlag << "\n";
    }

private:
    AutoState currentState;
    unsigned retryCount;
    unsigned errorFlag;
    std::array<Telemetry, 8> history;
};

int main() {
    Autopilot_NC ap;
    for (int i = 0; i < 6; ++i) {
        ap.step();
        ap.logStatus();
    }
    return 0;
}