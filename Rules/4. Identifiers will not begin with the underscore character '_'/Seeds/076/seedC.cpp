// Context: Crossover frequency setter

// Seed 076 — C: function and parameter without underscore prefix
#include <iostream>
void set_crossover(float freq_hz) { // C
    std::cout << "xover=" << freq_hz << "Hz\n";
}
int main(){
    set_crossover(2000.0F);
    return 0;
}