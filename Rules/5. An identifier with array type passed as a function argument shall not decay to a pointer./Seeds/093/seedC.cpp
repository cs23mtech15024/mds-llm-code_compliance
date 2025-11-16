// Context: Water level sensor array

// Seed 093 — C: water levels by reference
#include <iostream>
void monitor_tank_levels(float (&levels)[8]) { // C
    std::cout << "tank0=" << levels[0] << "\n";
}
int main(){
    float tank_levels[8] = {75.5F};
    monitor_tank_levels(tank_levels);
    return 0;
}