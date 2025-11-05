// Context: Sensor calibration offset variable — Expanded program

// ------ Non-Compliant Program (002_nc.cpp)
// Context: Sensor calibration offset handling
// NC: identifiers begin with '_'
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <numeric>

namespace _cal_rule_002 {

struct _Sample {
    int id;
    double value;
};

static bool _validId(int id) {
    return id >= 0;
}

static double _applyOffset(double v, double _calibration_offset) {
    return v + _calibration_offset;
}

class _Analyzer {
public:
    _Analyzer() = default;

    double _mean(const std::vector<_Sample> &s) const {
        if (s.empty()) { return 0.0; }
        double sum = 0.0;
        for (const auto &x : s) { sum += x.value; }
        return sum / static_cast<double>(s.size());
    }

    void _print(const std::vector<_Sample> &s) const {
        for (const auto &x : s) {
            std::cout << "id=" << x.id << " val=" << x.value << std::endl;
        }
    }
};

} // namespace _cal_rule_002

int main() {
    using namespace _cal_rule_002;
    double _calibration_offset = 2.5;
    std::vector<_Sample> in;
    in.push_back({0, _applyOffset(98.0, _calibration_offset)});
    in.push_back({1, _applyOffset(99.1, _calibration_offset)});
    in.push_back({2, _applyOffset(97.8, _calibration_offset)});
    std::vector<_Sample> out;
    for (const auto &s : in) {
        if (_validId(s.id)) { out.push_back(s); }
    }
    _Analyzer a;
    a._print(out);
    std::cout << "mean=" << a._mean(out) << std::endl;
    return 0;
}
