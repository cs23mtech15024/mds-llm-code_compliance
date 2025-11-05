// Context: State machine current state — Expanded program

// ------ Non-Compliant Program (087_nc.cpp)
// Context: Print state machine current state value
// MISRA: Identifiers must not begin with '_'
// NC: variable and helpers begin with '_'
#include <iostream>
#include <string>

namespace _sm_rule_087 {

enum class _State { // NC class name is also underscored intentionally here
    Idle = 0,
    Active = 1,
    Error = 2
};

static const char* _name(_State s) { // NC
    switch (s) {
        case _State::Idle: return "Idle";
        case _State::Active: return "Active";
        default: return "Error";
    }
}

static void _print(int _current_state) { // NC
    _State s = (_current_state == 0) ? _State::Idle : ((_current_state == 1) ? _State::Active : _State::Error);
    std::cout << "state=" << _name(s) << std::endl;
}

} // namespace _sm_rule_087

int main() {
    using namespace _sm_rule_087;
    _print(1);
    return 0;
}
