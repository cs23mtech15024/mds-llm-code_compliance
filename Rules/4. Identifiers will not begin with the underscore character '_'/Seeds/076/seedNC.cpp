// Context: Crossover frequency setter

// Seed 076 — NC: function and parameter start with underscore
#include <iostream>
void _set_crossover(float _freq_hz) { // NC
    std::cout << "xover=" << _freq_hz << "Hz\n";
}
int main(){
    _set_crossover(2000.0F);
    return 0;
}