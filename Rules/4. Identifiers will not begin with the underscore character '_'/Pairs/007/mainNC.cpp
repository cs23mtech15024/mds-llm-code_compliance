// Context: GPS coordinate converter — Expanded program

// ------ Non-Compliant Program (007_nc.cpp)
// Context: Lat/Lon echo
// NC: variables begin with '_'
#include <iostream>
#include <iomanip>

namespace _geo_rule_007 {

static void _print(double _latitude, double _longitude) {
    std::cout << std::fixed << std::setprecision(4) << _latitude << "," << _longitude << std::endl;
}

static bool _valid(double v) {
    return (v >= -180.0) && (v <= 180.0);
}

} // namespace _geo_rule_007

int main() {
    using namespace _geo_rule_007;
    double _latitude = 37.7749;
    double _longitude = -122.4194;
    if (_valid(_latitude) && _valid(_longitude)) {
        _print(_latitude, _longitude);
    }
    return 0;
}
