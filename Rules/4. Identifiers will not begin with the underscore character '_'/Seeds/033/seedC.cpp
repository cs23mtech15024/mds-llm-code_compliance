// Context: Sampling frequency divider

// Seed 033 — C: variables without underscore prefix
#include <iostream>
int main(){
    int input_freq = 48000; // C
    int divisor = 4; // C
    std::cout << "output_freq=" << input_freq / divisor << "\n";
    return 0;
}