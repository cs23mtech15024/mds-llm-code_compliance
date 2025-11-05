// Context: Signal filter bandwidth function

// Seed 012 — C: function parameter without underscore prefix
#include <iostream>
void set_bandwidth(float bw_hz) { // C
    std::cout << "bandwidth=" << bw_hz << "Hz\n";
}
int main(){
    set_bandwidth(1000.0F);
    return 0;
}