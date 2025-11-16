// Context: Tachometer pulse intervals

// Seed 088 — C: pulse intervals by reference
#include <iostream>
long calculate_rpm_from_pulses(long (&intervals)[10]) { // C
    return 60000000L / intervals[0];
}
int main(){
    long tach_intervals[10] = {10000};
    std::cout << "rpm=" << calculate_rpm_from_pulses(tach_intervals) << "\n";
    return 0;
}