// Context: State machine current state — Expanded program

// ------ Compliant Program (087_c.cpp)
// Context: Print state machine current state value
// C: identifiers do not begin with '_'
#include <iostream>
#include <string>

namespace sm_rule_087 {

enum class State {
    Idle = 0,
    Active = 1,
    Error = 2
};

static const char* name(State s) {
    switch (s) {
        case State::Idle: return "Idle";
        case State::Active: return "Active";
        default: return "Error";
    }
}

static void print(int current_state) {
    State s = (current_state == 0) ? State::Idle : ((current_state == 1) ? State::Active : State::Error);
    std::cout << "state=" << name(s) << std::endl;
}

} // namespace sm_rule_087

int main() {
    using namespace sm_rule_087;
    print(1);
    return 0;
}
