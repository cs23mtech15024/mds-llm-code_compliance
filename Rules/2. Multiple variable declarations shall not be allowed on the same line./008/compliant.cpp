// ------ Compliant
// Seed: Non-compliant: Point p1, p2;   // Compliant: Point p1; Point p2;
// Context: Waypoint points for mission planning in a DRDO subsystem.
// Violation: Declaring multiple objects on the same line (MISRA C++:2008 Rule 8-0-1).
// Source: MathWorks / Polyspace — MISRA C++:2008 Rule 8-0-1; style guidance on single-declaration-per-line.  [oai_citation:2‡it.mathworks.com](https://it.mathworks.com/help/bugfinder/ref/misrac2008rule801.html?utm_source=chatgpt.com)

#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <thread>
#include <sstream>

// Simple Point type for waypoints
struct Point {
    double x;
    double y;
    Point(double xx = 0.0, double yy = 0.0) : x(xx), y(yy) {}
};

// Compute Euclidean distance
double dist(const Point &a, const Point &b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return std::sqrt(dx*dx + dy*dy);
}

// Compliant: declare each Point variable on its own line
void waypoint_demo_C(const std::string &log = "wp_c.log") {
    Point p1;
    Point p2;
    // (compliant: single declarator per declaration)

    // deterministic list of waypoints
    std::vector<Point> waypoints = {
        Point(0.0, 0.0), Point(3.0, 4.0),
        Point(6.0, 8.0), Point(9.0, 12.0)
    };

    // pick first two for demonstration
    p1 = waypoints[0];
    p2 = waypoints[1];

    double d = dist(p1, p2);

    std::ofstream out(log, std::ios::app);
    std::ostringstream s;
    s << std::fixed << std::setprecision(3);
    s << "[C] p1=(" << p1.x << "," << p1.y << ") p2=(" << p2.x << "," << p2.y << ") d=" << d << '\n';

    std::cout << s.str();
    if (out) { out << s.str(); out.close(); }

    // deterministic pause
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
}

int main() {
    waypoint_demo_C();
    return 0;
}