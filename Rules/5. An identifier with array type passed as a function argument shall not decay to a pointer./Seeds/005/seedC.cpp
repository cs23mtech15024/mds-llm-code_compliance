// Context: GPS coordinate waypoint validator

// Seed 005 — C: coordinate array by reference
#include <iostream>
bool validate_waypoints(double (&coords)[10]) { // C
    return coords[0] >= -90.0 && coords[0] <= 90.0;
}
int main(){
    double waypoints[10] = {37.7749, -122.4194};
    std::cout << "valid=" << validate_waypoints(waypoints) << "\n";
    return 0;
}