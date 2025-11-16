// Context: Printer nozzle temperature zones

// Seed 094 — C: nozzle temps by reference
#include <iostream>
void calibrate_hotend(int (&temperatures)[5]) { // C
    temperatures[0] = 210;
    std::cout << "nozzle0=" << temperatures[0] << "\n";
}
int main(){
    int hotend_temps[5] = {0};
    calibrate_hotend(hotend_temps);
    return 0;
}