// Context: Fuel injector pulse widths

// Seed 053 — NC: pulse widths decay to pointer
#include <iostream>
void set_injector_timing(int pulse_widths[]) { // NC
    pulse_widths[0] = 1500;
    std::cout << "inj0_us=" << pulse_widths[0] << "\n";
}
int main(){
    int injector_pulses[8] = {0};
    set_injector_timing(injector_pulses);
    return 0;
}