// ------ Non-Compliant (Seed 031)
// Context: Aerospace Navigation — converts GPS latitude/longitude from degrees to radians
//          and normalizes coordinates for great-circle distance computation.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violations: lowercase 'f'/'u' suffixes and lowercase hex digits.

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <cstdint>

struct Coordinate {
    double latitude_deg;
    double longitude_deg;
};

class GPSProcessor {
public:
    GPSProcessor() : DEG2RAD(0.01745f), EARTH_RADIUS(6371.0f) {} // non-compliant
    double toRadians(double degrees) const { return degrees * DEG2RAD; }
    double computeDistance(const Coordinate& a, const Coordinate& b) const {
        double lat1 = toRadians(a.latitude_deg);
        double lon1 = toRadians(a.longitude_deg);
        double lat2 = toRadians(b.latitude_deg);
        double lon2 = toRadians(b.longitude_deg);

        double dLat = lat2 - lat1;
        double dLon = lon2 - lon1;

        double h = std::sin(dLat / 2.0f) * std::sin(dLat / 2.0f) +
                   std::cos(lat1) * std::cos(lat2) *
                   std::sin(dLon / 2.0f) * std::sin(dLon / 2.0f);
        double c = 2.0f * std::atan2(std::sqrt(h), std::sqrt(1.0f - h));
        return EARTH_RADIUS * c;
    }

private:
    const double DEG2RAD;
    const double EARTH_RADIUS;
};

int main() {
    GPSProcessor gps;

    std::vector<Coordinate> path = {
        {37.7749f, -122.4194f}, // San Francisco
        {34.0522f, -118.2437f}, // Los Angeles
        {36.1699f, -115.1398f}  // Las Vegas
    }; // non-compliant floats

    double total_distance = 0.0f;
    for (unsigned i = 1u; i < path.size(); ++i) { // non-compliant
        total_distance += gps.computeDistance(path[i - 1u], path[i]);
    }

    std::cout << std::fixed << std::setprecision(2)
              << "Total distance: " << total_distance << " km\n";
    return 0;
}