// Context: Damping coefficient setter — Expanded program

// ------ Compliant Program (055_c.cpp)
// Context: Set damping coef and display
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace dmp_rule_055 {

class Plant {
public:
    void set_damping(float coef) {
        coef_ = (coef < 0.0F) ? 0.0F : ((coef > 1.0F) ? 1.0F : coef);
    }
    float value() const { return coef_; }
private:
    float coef_ = 0.0F;
};

static void demo(const std::vector<float>& vals) {
    Plant p;
    for (float v : vals) {
        p.set_damping(v);
        std::cout << std::fixed << std::setprecision(3)
                  << "damping=" << p.value() << std::endl;
    }
}

} // namespace dmp_rule_055

int main() {
    using namespace dmp_rule_055;
    std::vector<float> vals = {-0.2F, 0.7F, 1.5F};
    demo(vals);
    return 0;
}
