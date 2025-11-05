// Context: Damping coefficient setter — Expanded program

// ------ Non-Compliant Program (055_nc.cpp)
// Context: Set damping coef and display
// MISRA: Identifiers must not begin with '_'
// NC: function and parameter begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _dmp_rule_055 {

class _Plant {
public:
    void _set_damping(float _coef) { // NC
        coef_ = (_coef < 0.0F) ? 0.0F : ((_coef > 1.0F) ? 1.0F : _coef);
    }
    float value() const { return coef_; }
private:
    float coef_ = 0.0F;
};

static void _demo(const std::vector<float>& _vals) {
    _Plant p;
    for (float v : _vals) {
        p._set_damping(v);
        std::cout << std::fixed << std::setprecision(3)
                  << "damping=" << p.value() << std::endl;
    }
}

} // namespace _dmp_rule_055

int main() {
    using namespace _dmp_rule_055;
    std::vector<float> vals = {-0.2F, 0.7F, 1.5F};
    _demo(vals);
    return 0;
}
