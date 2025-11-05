// Context: Step counter accumulator

// Seed 042 — NC: variable starts with underscore
#include <iostream>
int main(){
    int _step_count = 5000; // NC
    _step_count += 100;
    std::cout << "steps=" << _step_count << "\n";
    return 0;
}