// Context: PID controller gain schedule

// Seed 064 — NC: gain schedule decays to pointer
#include <iostream>
void load_pid_gains(float gains[]) { // NC
    gains[0] = 1.5F;
    std::cout << "kp=" << gains[0] << "\n";
}
int main(){
    float pid_schedule[9] = {0};
    load_pid_gains(pid_schedule);
    return 0;
}