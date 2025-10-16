// ------ Compliant
// Seed: Non-compliant: double x, y;   // Compliant: double x; double y;
// Context: Guidance/trajectory helper for DRDO mission-planning component.
// Violation: Declaring multiple member/automatic variables on the same line (MISRA C++:2008 Rule 8-0-1).
// Source: MathWorks / Polyspace — MISRA C++:2008 Rule 8-0-1.  [oai_citation:3‡MathWorks](https://es.mathworks.com/help///bugfinder/ref/misrac2008rule801.html?utm_source=chatgpt.com)

#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <thread>
#include <sstream>

struct WaypointC {
    // Compliant: each member declared separately (single declarator per declaration)
    double x;
    double y; // compliant: double x; double y;
    WaypointC(double xx = 0.0, double yy = 0.0) : x(xx), y(yy) {}
};

double distance(const WaypointC &a, const WaypointC &b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return std::sqrt(dx*dx + dy*dy);
}

void trajectory_compute_C(const std::vector<WaypointC> &wp, const std::string &logpath = "traj_c.log") {
    if (wp.empty()) return;
    std::ofstream out(logpath, std::ios::app);
    if (!out) std::cerr << "[C] Failed to open log\n";

    double total = 0.0;
    double maxd = 0.0;
    // iterate consecutive waypoint pairs, accumulate distances
    for (size_t i = 1; i < wp.size(); ++i) {
        double d = distance(wp[i-1], wp[i]);
        total += d;
        if (d > maxd) maxd = d;
        if (out) out << "[C] seg " << i-1 << "->" << i << " d=" << std::fixed << std::setprecision(3) << d << '\n';
    }

    double avg = total / static_cast<double>(wp.size() - 1);
    std::ostringstream s;
    s << std::fixed << std::setprecision(3);
    s << "[C] total=" << total << " avg=" << avg << " max=" << maxd << '\n';

    std::cout << s.str();
    if (out) { out << s.str(); out.close(); }

    // deterministic pause to mimic processing timing
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
}

int main() {
    // deterministic waypoint list
    std::vector<WaypointC> waypoints = {
        WaypointC(0.0, 0.0),
        WaypointC(3.0, 4.0),
        WaypointC(6.0, 8.0),
        WaypointC(9.0, 12.0)
    };

    trajectory_compute_C(waypoints);
    return 0;
}