// Context: Sonar ping response times

// Seed 067 — NC: ping times decay to pointer
#include <iostream>
long calculate_distance(long ping_times[]) { // NC
    return ping_times[0] / 58;
}
int main(){
    long sonar_pings[16] = {2900};
    std::cout << "dist_cm=" << calculate_distance(sonar_pings) << "\n";
    return 0;
}