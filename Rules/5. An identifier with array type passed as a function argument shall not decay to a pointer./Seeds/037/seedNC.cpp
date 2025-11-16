// Context: Wheel encoder pulse counts

// Seed 037 — NC: encoder counts decay to pointer
#include <iostream>
long get_total_pulses(long pulse_counts[]) { // NC
    return pulse_counts[0] + pulse_counts[1];
}
int main(){
    long encoder_pulses[4] = {1000, 1050};
    std::cout << "total=" << get_total_pulses(encoder_pulses) << "\n";
    return 0;
}