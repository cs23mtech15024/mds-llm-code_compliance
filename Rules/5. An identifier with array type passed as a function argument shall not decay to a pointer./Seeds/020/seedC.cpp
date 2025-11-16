// Context: Ultrasonic sensor echo times

// Seed 020 — C: echo time array by reference
#include <iostream>
long get_echo_time(long (&echo_times)[8]) { // C
    return echo_times[0];
}
int main(){
    long ultrasonic_echos[8] = {1500, 1600};
    std::cout << "echo=" << get_echo_time(ultrasonic_echos) << "\n";
    return 0;
}