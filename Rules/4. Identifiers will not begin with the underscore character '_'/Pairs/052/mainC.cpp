// Context: Exponential moving average — Expanded program

// ------ Compliant Program (052_c.cpp)
// Context: EMA update stream
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace ema_rule_052 {

static float clamp01(float x) {
    if (x < 0.0F) { return 0.0F; }
    if (x > 1.0F) { return 1.0F; }
    return x;
}

static float ema_update(float prev, float new_val, float alpha) {
    float a = clamp01(alpha);
    return a * new_val + (1.0F - a) * prev;
}

static void process(const std::vector<float>& vals, float alpha) {
    float y = 0.0F;
    for (float v : vals) {
        y = ema_update(y, v, alpha);
        std::cout << std::fixed << std::setprecision(3)
                  << "in=" << v << " ema=" << y << std::endl;
    }
}

} // namespace ema_rule_052

int main() {
    using namespace ema_rule_052;
    std::vector<float> v = {100.0F, 105.0F, 103.0F, 110.0F};
    process(v, 0.2F);
    return 0;
}
