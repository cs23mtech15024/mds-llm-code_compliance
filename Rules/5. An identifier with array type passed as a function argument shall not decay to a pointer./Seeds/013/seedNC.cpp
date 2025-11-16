// Context: Pressure sensor reading history

// Seed 013 — NC: pressure history decays to pointer
#include <iostream>
float calculate_average(float pressures[]) { // NC
    return (pressures[0] + pressures[1]) / 2.0F;
}
int main(){
    float pressure_log[50] = {101.3F, 101.5F};
    std::cout << "avg=" << calculate_average(pressure_log) << "\n";
    return 0;
}