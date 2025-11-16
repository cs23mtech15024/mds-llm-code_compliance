// Context: GPS coordinate waypoint validator

// ------ Compliant Program (005_c.cpp)
// Context: GPS coordinate waypoint validator
// C: coords accepted by reference to array
#include <iostream>
#include <iomanip>

namespace gps_005_c {

static bool in_range(double v, double lo, double hi) { return (v >= lo) && (v <= hi); }

bool validate_waypoints(double (&coords)[10]) { // C
    bool ok_lat0 = in_range(coords[0], -90.0, 90.0);
    bool ok_lon0 = in_range(coords[1], -180.0, 180.0);
    return ok_lat0 && ok_lon0;
}

} // namespace gps_005_c

int main() {
    using namespace gps_005_c;
    double waypoints[10] = {37.7749, -122.4194};
    std::cout << "valid=" << validate_waypoints(waypoints) << "\n";
    return 0;
}
