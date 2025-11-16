// Context: Spindle speed feedback history

// Seed 086 — NC: spindle speeds decay to pointer
#include <iostream>
void monitor_spindle(int speeds[]) { // NC
    std::cout << "rpm=" << speeds[0] << "\n";
}
int main(){
    int spindle_rpms[50] = {3000};
    monitor_spindle(spindle_rpms);
    return 0;
}