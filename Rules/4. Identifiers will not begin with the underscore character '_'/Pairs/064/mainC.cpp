// Context: Slew rate limit calculator — Expanded program

// ------ Compliant Program (064_c.cpp)
// Context: slew = delta/time
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace slew_rule_064 {

static float safeTime(float t) {
    return (t <= 0.0F) ? 1.0F : t;
}

static float calc_slew_rate(float delta, float time) {
    return delta / safeTime(time);
}

static void table(const std::vector<std::pair<float,float>>& cases) {
    for (const auto &p : cases) {
        std::cout << std::fixed << std::setprecision(2)
                  << "slew=" << calc_slew_rate(p.first, p.second) << std::endl;
    }
}

} // namespace slew_rule_064

int main() {
    using namespace slew_rule_064;
    std::vector<std::pair<float,float>> cases = {{10.0F,0.1F},{-5.0F,0.0F}};
    table(cases);
    return 0;
}
