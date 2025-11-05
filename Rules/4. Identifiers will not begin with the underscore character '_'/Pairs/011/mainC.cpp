// Context: Battery voltage monitor — Expanded program

// ------ Compliant Program (011_c.cpp)
// Context: Battery voltage monitor
// C: no identifiers begin with '_'
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

namespace bat_rule_011 {

struct Sample {
    float voltage;
    float current;
};

static float power(float v, float i) {
    return v * i;
}

static bool inRange(float v) {
    return (v >= 2.7F) && (v <= 4.3F);
}

static void print(const std::vector<Sample> &v) {
    for (const auto &s : v) {
        float p = power(s.voltage, s.current);
        std::cout << std::fixed << std::setprecision(2)
                  << "V=" << s.voltage
                  << " I=" << s.current
                  << " P=" << p << std::endl;
    }
}

static std::vector<Sample> filter(const std::vector<Sample> &in) {
    std::vector<Sample> out;
    out.reserve(in.size());
    for (const auto &s : in) {
        if (inRange(s.voltage)) { out.push_back(s); }
    }
    return out;
}

} // namespace bat_rule_011

int main() {
    using namespace bat_rule_011;
    std::vector<Sample> raw;
    raw.push_back({3.70F, 0.50F});
    raw.push_back({2.50F, 0.40F});
    raw.push_back({4.10F, 0.60F});
    auto ok = filter(raw);
    print(ok);
    return 0;
}
