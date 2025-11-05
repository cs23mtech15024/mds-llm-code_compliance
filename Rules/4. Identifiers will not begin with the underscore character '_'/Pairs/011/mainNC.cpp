// Context: Battery voltage monitor — Expanded program

// ------ Non-Compliant Program (011_nc.cpp)
// Context: Battery voltage monitor
// MISRA: Identifiers must not begin with '_'
// NC: leading '_' identifiers are used
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

namespace _bat_rule_011 {

struct _Sample {
    float _voltage;
    float _current;
};

static float _power(float v, float i) {
    return v * i;
}

static bool _inRange(float v) {
    return (v >= 2.7F) && (v <= 4.3F);
}

static void _print(const std::vector<_Sample> &_v) {
    for (const auto &s : _v) {
        float p = _power(s._voltage, s._current);
        std::cout << std::fixed << std::setprecision(2)
                  << "V=" << s._voltage
                  << " I=" << s._current
                  << " P=" << p << std::endl;
    }
}

static std::vector<_Sample> _filter(const std::vector<_Sample> &in) {
    std::vector<_Sample> out;
    out.reserve(in.size());
    for (const auto &s : in) {
        if (_inRange(s._voltage)) { out.push_back(s); }
    }
    return out;
}

} // namespace _bat_rule_011

int main() {
    using namespace _bat_rule_011;
    std::vector<_Sample> raw;
    raw.push_back({_Sample{3.70F, 0.50F}});
    raw.push_back({_Sample{2.50F, 0.40F}});
    raw.push_back({_Sample{4.10F, 0.60F}});
    auto ok = _filter(raw);
    _print(ok);
    return 0;
}
