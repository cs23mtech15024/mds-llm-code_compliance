// Context: Notch filter center frequency — Expanded program

// ------ Compliant Program (072_c.cpp)
// Context: Notch center frequency in Hz
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace notch_rule_072 {

static float clip_hz(float v) {
    if (v < 0.0F) { return 0.0F; }
    if (v > 100000.0F) { return 100000.0F; }
    return v;
}

static void set_center(float &center_hz, float v) {
    center_hz = clip_hz(v);
}

static void demo(const std::vector<float>& vals) {
    float center_hz = 1000.0F;
    for (float v : vals) {
        set_center(center_hz, v);
        std::cout << std::fixed << std::setprecision(1)
                  << "notch_f=" << center_hz << "Hz" << std::endl;
    }
}

} // namespace notch_rule_072

int main() {
    using namespace notch_rule_072;
    std::vector<float> vals = {1000.0F, -20.0F, 123456.0F};
    demo(vals);
    return 0;
}
