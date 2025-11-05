// Context: Sampling frequency divider

// Seed 033 — NC: variables start with underscore
#include <iostream>
int main(){
    int _input_freq = 48000; // NC
    int _divisor = 4; // NC
    std::cout << "output_freq=" << _input_freq / _divisor << "\n";
    return 0;
}