// Context: Frequency response analyzer

// Seed 043 — C: function and parameter without underscore prefix
#include <iostream>
float analyze_freq(float hz) { // C
    return 1.0F / hz;
}
int main(){
    std::cout << "period=" << analyze_freq(1000.0F) << "\n";
    return 0;
}