// Context: Sensor data processing for industrial control system.
// Rule violated: MISRA C++ 2-13-4 – Literal suffixes and exponents shall be upper case.
// Seed: Non-compliant: const double scale = 1.0e-3;   // Compliant: const double scale = 1.0E-3;
// Violation: Lowercase ‘e’ used in scientific literals.

#include <iostream>
#include <vector>
#include <numeric>

class Sensor {
public:
    Sensor(double s, double o) : scale(s), offset(o) {}

    double calibrate(double raw) const {
        return raw * scale + offset;
    }

private:
    double scale;   // e.g., 1.0e-3 (millivolt conversion)
    double offset;  // e.g., 2.5e1  (bias offset)
};

int main() {
    std::vector<double> raw_values = { 1000.0, 2000.0, 3000.0 };
    Sensor s(1.0e-3, 2.5e1);  // NC literals

    std::vector<double> calibrated;
    for (auto v : raw_values) {
        calibrated.push_back(s.calibrate(v));
    }

    double avg = std::accumulate(calibrated.begin(), calibrated.end(), 0.0) / calibrated.size();
    std::cout << "Average calibrated value: " << avg << "\n";
    return 0;
}