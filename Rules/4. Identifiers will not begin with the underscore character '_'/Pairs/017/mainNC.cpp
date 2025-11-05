// Context: Navigation waypoint distance — Expanded program

// ------ Non-Compliant Program (017_nc.cpp)
// Context: Distance squared calculator
// MISRA: Identifiers must not begin with '_'
// NC: variables and helpers begin with '_'
#include <iostream>
#include <cmath>
#include <iomanip>

namespace _nav_rule_017 {

static double _sq(double v) { return v * v; }

static double _dist2(double _x1, double _y1, double _x2, double _y2) {
    return _sq(_x2 - _x1) + _sq(_y2 - _y1);
}

static void _print(double _x1, double _y1, double _x2, double _y2) {
    std::cout << std::fixed << std::setprecision(2)
              << "d2=" << _dist2(_x1, _y1, _x2, _y2) << std::endl;
}

} // namespace _nav_rule_017

int main() {
    using namespace _nav_rule_017;
    double _x1 = 0.0;
    double _y1 = 0.0;
    double _x2 = 100.0;
    double _y2 = 100.0;
    _print(_x1, _y1, _x2, _y2);
    return 0;
}
