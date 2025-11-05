// Context: Previous error state tracker — Expanded program

// ------ Non-Compliant Program (082_nc.cpp)
// Context: Track previous error for derivative term
// MISRA: Identifiers must not begin with '_'
// NC: variable begins with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _perr_rule_082 {

static float _deriv(float curr, float _prev_error, float dt) { // NC
    if (dt <= 0.0F) { return 0.0F; }
    return (curr - _prev_error) / dt;
}

static void _run(const std::vector<float>& _errors, float dt) {
    float _prev_error = 0.0F;
    for (float e : _errors) {
        float d = _deriv(e, _prev_error, dt);
        std::cout << std::fixed << std::setprecision(3)
                  << "prev_err=" << _prev_error << " deriv=" << d << std::endl;
        _prev_error = e;
    }
}

} // namespace _perr_rule_082

int main() {
    using namespace _perr_rule_082;
    std::vector<float> errs = {0.0F, 0.5F, 0.2F, 0.4F};
    _run(errs, 0.1F);
    return 0;
}
