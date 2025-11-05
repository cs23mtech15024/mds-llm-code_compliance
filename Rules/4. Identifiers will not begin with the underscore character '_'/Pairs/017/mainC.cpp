// Context: Navigation waypoint distance — Expanded program

// ------ Compliant Program (017_c.cpp)
// Context: Distance squared calculator
// C: identifiers do not begin with '_'
#include <iostream>
#include <cmath>
#include <iomanip>

namespace nav_rule_017 {

static double sq(double v) { return v * v; }

static double dist2(double x1, double y1, double x2, double y2) {
    return sq(x2 - x1) + sq(y2 - y1);
}

static void print(double x1, double y1, double x2, double y2) {
    std::cout << std::fixed << std::setprecision(2)
              << "d2=" << dist2(x1, y1, x2, y2) << std::endl;
}

} // namespace nav_rule_017

int main() {
    using namespace nav_rule_017;
    double x1 = 0.0;
    double y1 = 0.0;
    double x2 = 100.0;
    double y2 = 100.0;
    print(x1, y1, x2, y2);
    return 0;
}
