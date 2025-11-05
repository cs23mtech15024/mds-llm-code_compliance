// Context: Message queue depth monitor — Expanded program

// ------ Compliant Program (029_c.cpp)
// Context: Queue depth printing
// C: identifiers have no leading '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace q_rule_029 {

static int clip(int v) {
    if (v < 0) { return 0; }
    if (v > 1000) { return 1000; }
    return v;
}

static void printDepth(int queue_depth) {
    std::cout << "depth=" << clip(queue_depth) << std::endl;
}

static void replay(const std::vector<int> &depths) {
    for (int d : depths) { printDepth(d); }
}

} // namespace q_rule_029

int main() {
    using namespace q_rule_029;
    std::vector<int> depths = {25, -5, 1200};
    replay(depths);
    return 0;
}
