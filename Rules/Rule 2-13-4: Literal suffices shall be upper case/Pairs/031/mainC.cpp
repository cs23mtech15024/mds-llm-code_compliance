// ------ Compliant (Seed 031)
// Context: Aerospace Navigation — converts GPS latitude/longitude from degrees to radians
//          and normalizes coordinates for great-circle distance computation.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Fixes: all suffixes changed to uppercase ('F','U') and hex digits to uppercase.

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
    GPSProcessor() : DEG2RAD(0.01745F), EARTH_RADIUS(6371.0F) {} // compliant
    double toRadians(double degrees) const { return degrees * DEG2RAD; }
    double computeDistance(const Coordinate& a, const Coordinate& b) const {
        double lat1 = toRadians(a.latitude_deg);
        double lon1 = toRadians(a.longitude_deg);
        double lat2 = toRadians(b.latitude_deg);
        double lon2 = toRadians(b.longitude_deg);

        double dLat = lat2 - lat1;
        double dLon = lon2 - lon1;

        double h = std::sin(dLat / 2.0F) * std::sin(dLat / 2.0F) +
                   std::cos(lat1) * std::cos(lat2) *
                   std::sin(dLon / 2.0F) * std::sin(dLon / 2.0F);
        double c = 2.0F * std::atan2(std::sqrt(h), std::sqrt(1.0F - h));
        return EARTH_RADIUS * c;
    }

private:
    const double DEG2RAD;
    const double EARTH_RADIUS;
};

int main() {
    GPSProcessor gps;

    std::vector<Coordinate> path = {
        {37.7749F, -122.4194F}, // San Francisco
        {34.0522F, -118.2437F}, // Los Angeles
        {36.1699F, -115.1398F}  // Las Vegas
    }; // compliant floats

    double total_distance = 0.0F;
    for (unsigned i = 1U; i < path.size(); ++i) { // compliant
        total_distance += gps.computeDistance(path[i - 1U], path[i]);
    }

    std::cout << std::fixed << std::setprecision(2)
              << "Total distance: " << total_distance << " km\n";
    return 0;
}