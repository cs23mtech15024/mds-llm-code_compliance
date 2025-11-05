// Context: Signal filter bandwidth function

// Seed 012 — NC: function parameter starts with underscore
#include <iostream>
void set_bandwidth(float _bw_hz) { // NC
    std::cout << "bandwidth=" << _bw_hz << "Hz\n";
}
int main(){
    set_bandwidth(1000.0F);
    return 0;
}