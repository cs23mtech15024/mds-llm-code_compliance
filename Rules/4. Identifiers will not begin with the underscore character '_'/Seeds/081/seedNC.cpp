// Context: Error accumulator variable

// Seed 081 — NC: variable starts with underscore
#include <iostream>
int main(){
    float _error_sum = 0.0F; // NC
    _error_sum += 0.5F;
    std::cout << "err_sum=" << _error_sum << "\n";
    return 0;
}