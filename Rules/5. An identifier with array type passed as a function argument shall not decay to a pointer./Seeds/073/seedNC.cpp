// Context: Inverter switching frequency table

// Seed 073 — NC: frequency table decays to pointer
#include <iostream>
void set_switching_freq(int frequencies[]) { // NC
    frequencies[0] = 20000;
    std::cout << "freq=" << frequencies[0] << "Hz\n";
}
int main(){
    int inverter_freqs[10] = {0};
    set_switching_freq(inverter_freqs);
    return 0;
}