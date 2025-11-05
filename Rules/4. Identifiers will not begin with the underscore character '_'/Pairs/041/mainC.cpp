// Context: Distance measurement filter — Expanded program

// ------ Compliant Program (041_c.cpp)
// Context: First-order filter apply
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace flt_rule_041 {

static float clip(float v, float lo, float hi) {
    if (v < lo) { return lo; }
    if (v > hi) { return hi; }
    return v;
}

class Filter {
public:
    Filter() : alpha_(0.5F) { }

    void setAlpha(float a) { alpha_ = clip(a, 0.0F, 1.0F); }

    float apply_filter(float raw, float alpha) {
        setAlpha(alpha);
        return alpha_ * raw;
    }

private:
    float alpha_;
};

static void scan(const std::vector<float> &in) {
    Filter f;
    for (float r : in) {
        float out = f.apply_filter(r, 0.8F);
        std::cout << std::fixed << std::setprecision(2)
                  << "raw=" << r << " filtered=" << out << std::endl;
    }
}

} // namespace flt_rule_041

int main() {
    using namespace flt_rule_041;
    std::vector<float> in = {100.0F, 150.5F, 80.0F};
    scan(in);
    return 0;
}
