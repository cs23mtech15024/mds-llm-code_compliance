// Context: State transition validator

// Seed 088 — C: function without underscore prefix
#include <iostream>
bool is_valid_transition(int from, int to) { // C
    return to == from + 1;
}
int main(){
    std::cout << "valid=" << is_valid_transition(1, 2) << "\n";
    return 0;
}