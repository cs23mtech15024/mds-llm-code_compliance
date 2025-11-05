// Context: Setpoint value holder — Expanded program

// ------ Compliant Program (080_c.cpp)
// Context: Store and print setpoint
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace sp_rule_080 {

static float clip(float sp) {
    if (sp < -1000.0F) { return -1000.0F; }
    if (sp > 1000.0F) { return 1000.0F; }
    return sp;
}

static void set(float &setpoint, float v) {
    setpoint = clip(v);
}

static void print(float setpoint) {
    std::cout << std::fixed << std::setprecision(2)
              << "sp=" << setpoint << std::endl;
}

static void demo(const std::vector<float>& vals) {
    float setpoint = 25.0F;
    for (float v : vals) { set(setpoint, v); print(setpoint); }
}

} // namespace sp_rule_080

int main() {
    using namespace sp_rule_080;
    std::vector<float> vals = {25.0F, -1200.0F, 555.5F};
    demo(vals);
    return 0;
}
