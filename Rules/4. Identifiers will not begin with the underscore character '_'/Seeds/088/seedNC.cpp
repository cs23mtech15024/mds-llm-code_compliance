// Context: State transition validator

// Seed 088 — NC: function starts with underscore
#include <iostream>
bool _is_valid_transition(int from, int to) { // NC
    return to == from + 1;
}
int main(){
    std::cout << "valid=" << _is_valid_transition(1, 2) << "\n";
    return 0;
}