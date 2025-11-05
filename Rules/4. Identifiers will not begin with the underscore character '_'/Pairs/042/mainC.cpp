// Context: Step counter accumulator — Expanded program

// ------ Compliant Program (042_c.cpp)
// Context: Increment steps with bounds
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace step_rule_042 {

static int clip(int v, int lo, int hi) {
    if (v < lo) { return lo; }
    if (v > hi) { return hi; }
    return v;
}

static void add(int &step_count, int d) {
    int temp = clip(step_count + d, 0, 1000000);
    step_count = temp;
}

static void run(const std::vector<int> &deltas) {
    int step_count = 5000;
    for (int d : deltas) {
        add(step_count, d);
        std::cout << std::fixed << std::setprecision(0)
                  << "steps=" << step_count << std::endl;
    }
}

} // namespace step_rule_042

int main() {
    using namespace step_rule_042;
    std::vector<int> deltas = {100, 250, -50, 10000000};
    run(deltas);
    return 0;
}
