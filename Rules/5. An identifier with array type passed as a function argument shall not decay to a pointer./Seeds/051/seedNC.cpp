// Context: Barometric pressure trend analysis

// Seed 051 — NC: pressure trend decays to pointer
#include <iostream>
float analyze_trend(float pressures[]) { // NC
    return pressures[1] - pressures[0];
}
int main(){
    float pressure_trend[24] = {1013.0F, 1015.0F};
    std::cout << "delta=" << analyze_trend(pressure_trend) << "\n";
    return 0;
}