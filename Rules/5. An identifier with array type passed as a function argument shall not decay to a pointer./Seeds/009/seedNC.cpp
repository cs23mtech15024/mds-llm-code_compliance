// Context: Battery cell voltage monitor

// Seed 009 — NC: voltage array decays to pointer
#include <iostream>
float get_max_voltage(float voltages[]) { // NC
    return voltages[0];
}
int main(){
    float cell_voltages[12] = {3.7F, 3.8F, 3.6F};
    std::cout << "max_v=" << get_max_voltage(cell_voltages) << "\n";
    return 0;
}