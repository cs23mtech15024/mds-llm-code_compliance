// ------ Non-Compliant
// Pair 3 — Seed: 0x12bu -> 0x12BU
// Context: Applies bitmask for sensor calibration in DRDO data acquisition.
// Violation: lowercase hex letters and lowercase 'u' suffix inconsistent with JSF/DRDO readability rules.
// Source: JSF-AV hex convention & MISRA C++ Rule 2-13-4 (literal suffixes shall be upper case).

#include <cstdint>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

class SensorCalibrator_NC {
public:
    // Non-compliant mask (lowercase hex letters + lowercase suffix)
    static constexpr uint32_t CALIB_MASK = 0x12bu; // NC: lowercase hex suffix and 'u'
    SensorCalibrator_NC() : offsets{0, 0, 0, 0} {}

    void applyCalibration(std::vector<uint32_t>& readings) const {
        // Apply mask and compute corrected values
        for (auto &r : readings) {
            // Masking with non-compliant literal
            r = (r & CALIB_MASK);
        }
    }

    double computeAverage(const std::vector<uint32_t>& readings) const {
        if (readings.empty()) return 0.0;
        uint64_t sum = 0ull; // NC: lowercase 'ull' (kept here for realism)
        for (auto v : readings) sum += v;
        return static_cast<double>(sum) / static_cast<double>(readings.size());
    }

    void printReport(const std::vector<uint32_t>& readings) const {
        std::cout << "[NC] CALIB_MASK = 0x12bu, readings after mask: ";
        for (auto v : readings) std::cout << "0x" << std::hex << std::uppercase << v << " ";
        std::cout << std::dec << "\n";
        std::cout << "[NC] Average (raw): " << std::fixed << std::setprecision(2)
                  << computeAverage(readings) << "\n";
    }

private:
    std::vector<int> offsets;
};

int main() {
    // Simulated raw readings (some contain letters in hex form to show masking effect)
    std::vector<uint32_t> readings = { 0x12ABu, 0x1F2Cu, 0xFFFFu, 0x00FFu };
    SensorCalibrator_NC sc;
    sc.applyCalibration(readings);
    sc.printReport(readings);
    return 0;
}
