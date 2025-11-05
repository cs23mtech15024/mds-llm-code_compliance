// Context: Priority level selector — Expanded program

// ------ Compliant Program (039_c.cpp)
// Context: Select priority in [0..10]
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace prio_rule_039 {

static int clipPri(int p) {
    if (p < 0) { return 0; }
    if (p > 10) { return 10; }
    return p;
}

static void set(int &priority, int v) {
    priority = clipPri(v);
}

static void demo(const std::vector<int> &vals) {
    int priority = 5;
    for (int v : vals) {
        set(priority, v);
        std::cout << "prio=" << priority << std::endl;
    }
}

} // namespace prio_rule_039

int main() {
    using namespace prio_rule_039;
    std::vector<int> vals = {-1, 0, 3, 11};
    demo(vals);
    return 0;
}
