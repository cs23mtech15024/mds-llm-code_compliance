// Context: Semaphore initial count — Expanded program

// ------ Compliant Program (095_c.cpp)
// Context: Print configured semaphore initial count
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>

namespace sem_rule_095 {

static int bound(int v) {
    if (v < 0) { return 0; }
    if (v > 1000) { return 1000; }
    return v;
}

static void init(int sem_count) {
    std::cout << "sem_init=" << bound(sem_count) << std::endl;
}

static void demo(const std::vector<int>& vals) {
    for (int v : vals) { init(v); }
}

} // namespace sem_rule_095

int main() {
    using namespace sem_rule_095;
    std::vector<int> vals = {5, -1, 2000};
    demo(vals);
    return 0;
}
