// Context: Previous error state tracker — Expanded program

// ------ Compliant Program (082_c.cpp)
// Context: Track previous error for derivative term
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace perr_rule_082 {

static float deriv(float curr, float prev_error, float dt) {
    if (dt <= 0.0F) { return 0.0F; }
    return (curr - prev_error) / dt;
}

static void run(const std::vector<float>& errors, float dt) {
    float prev_error = 0.0F;
    for (float e : errors) {
        float d = deriv(e, prev_error, dt);
        std::cout << std::fixed << std::setprecision(3)
                  << "prev_err=" << prev_error << " deriv=" << d << std::endl;
        prev_error = e;
    }
}

} // namespace perr_rule_082

int main() {
    using namespace perr_rule_082;
    std::vector<float> errs = {0.0F, 0.5F, 0.2F, 0.4F};
    run(errs, 0.1F);
    return 0;
}
