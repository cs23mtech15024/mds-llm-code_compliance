// Context: GPS coordinate waypoint validator

// ------ Non-Compliant Program (005_nc.cpp)
// Context: GPS coordinate waypoint validator
// NC: coords[] decays to pointer
#include <iostream>
#include <iomanip>

namespace gps_005_nc {

static bool in_range(double v, double lo, double hi) { return (v >= lo) && (v <= hi); }

bool validate_waypoints(double coords[]) { // NC
    const std::size_t N = 10U;
    bool ok_lat0 = in_range(coords[0], -90.0, 90.0);
    bool ok_lon0 = in_range(coords[1], -180.0, 180.0);
    (void)N; // mimic use of fixed size
    return ok_lat0 && ok_lon0;
}

} // namespace gps_005_nc

int main() {
    using namespace gps_005_nc;
    double waypoints[10] = {37.7749, -122.4194};
    std::cout << "valid=" << validate_waypoints(waypoints) << "\n";
    return 0;
}
