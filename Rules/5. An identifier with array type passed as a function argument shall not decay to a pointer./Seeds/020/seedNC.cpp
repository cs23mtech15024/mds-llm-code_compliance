// Context: Ultrasonic sensor echo times

// Seed 020 — NC: echo time array decays to pointer
#include <iostream>
long get_echo_time(long echo_times[]) { // NC
    return echo_times[0];
}
int main(){
    long ultrasonic_echos[8] = {1500, 1600};
    std::cout << "echo=" << get_echo_time(ultrasonic_echos) << "\n";
    return 0;
}