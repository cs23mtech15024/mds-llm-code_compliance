// Context: PID controller gain schedule

// Seed 064 — C: gain schedule by reference
#include <iostream>
void load_pid_gains(float (&gains)[9]) { // C
    gains[0] = 1.5F;
    std::cout << "kp=" << gains[0] << "\n";
}
int main(){
    float pid_schedule[9] = {0};
    load_pid_gains(pid_schedule);
    return 0;
}