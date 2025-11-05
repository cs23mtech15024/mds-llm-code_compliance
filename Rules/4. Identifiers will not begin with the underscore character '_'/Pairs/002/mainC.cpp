// Context: Sensor calibration offset variable — Expanded program

// ------ Compliant Program (002_c.cpp)
// Context: Sensor calibration offset handling
// C: no identifiers begin with '_'
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <numeric>

namespace cal_rule_002 {

struct Sample {
    int id;
    double value;
};

static bool validId(int id) {
    return id >= 0;
}

static double applyOffset(double v, double calibration_offset) {
    return v + calibration_offset;
}

class Analyzer {
public:
    Analyzer() = default;

    double mean(const std::vector<Sample> &s) const {
        if (s.empty()) { return 0.0; }
        double sum = 0.0;
        for (const auto &x : s) { sum += x.value; }
        return sum / static_cast<double>(s.size());
    }

    void print(const std::vector<Sample> &s) const {
        for (const auto &x : s) {
            std::cout << "id=" << x.id << " val=" << x.value << std::endl;
        }
    }
};

} // namespace cal_rule_002

int main() {
    using namespace cal_rule_002;
    double calibration_offset = 2.5;
    std::vector<Sample> in;
    in.push_back({0, applyOffset(98.0, calibration_offset)});
    in.push_back({1, applyOffset(99.1, calibration_offset)});
    in.push_back({2, applyOffset(97.8, calibration_offset)});
    std::vector<Sample> out;
    for (const auto &s : in) {
        if (validId(s.id)) { out.push_back(s); }
    }
    Analyzer a;
    a.print(out);
    std::cout << "mean=" << a.mean(out) << std::endl;
    return 0;
}
