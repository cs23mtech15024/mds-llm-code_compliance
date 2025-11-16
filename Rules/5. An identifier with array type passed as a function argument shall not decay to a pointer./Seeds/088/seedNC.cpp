// Context: Tachometer pulse intervals

// Seed 088 — NC: pulse intervals decay to pointer
#include <iostream>
long calculate_rpm_from_pulses(long intervals[]) { // NC
    return 60000000L / intervals[0];
}
int main(){
    long tach_intervals[10] = {10000};
    std::cout << "rpm=" << calculate_rpm_from_pulses(tach_intervals) << "\n";
    return 0;
}