// Context: Water level sensor array

// Seed 093 — NC: water levels decay to pointer
#include <iostream>
void monitor_tank_levels(float levels[]) { // NC
    std::cout << "tank0=" << levels[0] << "\n";
}
int main(){
    float tank_levels[8] = {75.5F};
    monitor_tank_levels(tank_levels);
    return 0;
}