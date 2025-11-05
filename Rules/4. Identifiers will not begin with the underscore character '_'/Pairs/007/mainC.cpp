// Context: GPS coordinate converter — Expanded program

// ------ Compliant Program (007_c.cpp)
// Context: Lat/Lon echo
// C: identifiers have no leading '_'
#include <iostream>
#include <iomanip>

namespace geo_rule_007 {

static void print(double latitude, double longitude) {
    std::cout << std::fixed << std::setprecision(4) << latitude << "," << longitude << std::endl;
}

static bool valid(double v) {
    return (v >= -180.0) && (v <= 180.0);
}

} // namespace geo_rule_007

int main() {
    using namespace geo_rule_007;
    double latitude = 37.7749;
    double longitude = -122.4194;
    if (valid(latitude) && valid(longitude)) {
        print(latitude, longitude);
    }
    return 0;
}
