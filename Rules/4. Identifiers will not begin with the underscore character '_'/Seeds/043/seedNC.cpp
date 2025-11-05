// Context: Frequency response analyzer

// Seed 043 — NC: function and parameter start with underscore
#include <iostream>
float _analyze_freq(float _hz) { // NC
    return 1.0F / _hz;
}
int main(){
    std::cout << "period=" << _analyze_freq(1000.0F) << "\n";
    return 0;
}