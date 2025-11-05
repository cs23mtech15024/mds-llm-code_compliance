// Context: Frame counter incrementer — Expanded program

// ------ Compliant Program (031_c.cpp)
// Context: Frame counter increment utility
// C: no identifiers begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace frm_rule_031 {

static int clampNonNeg(int v) {
    if (v < 0) { return 0; }
    return v;
}

class FrameCounter {
public:
    FrameCounter() : count_(0) { }

    void increment_frame(int step) { // C
        count_ = clampNonNeg(count_ + step);
    }

    int value() const {
        return count_;
    }

private:
    int count_;
};

static void simulate(FrameCounter &c, const std::vector<int> &steps) {
    for (int s : steps) {
        c.increment_frame(s);
        std::cout << "step=" << s << " frames=" << c.value() << std::endl;
    }
}

} // namespace frm_rule_031

int main() {
    using namespace frm_rule_031;
    FrameCounter fc;
    std::vector<int> steps = {1, 1, 2, -5, 3};
    simulate(fc, steps);
    return 0;
}
