// Context: Spindle speed feedback history

// Seed 086 — C: spindle speeds by reference
#include <iostream>
void monitor_spindle(int (&speeds)[50]) { // C
    std::cout << "rpm=" << speeds[0] << "\n";
}
int main(){
    int spindle_rpms[50] = {3000};
    monitor_spindle(spindle_rpms);
    return 0;
}