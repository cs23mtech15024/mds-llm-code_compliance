// Context: Task priority assignment — Expanded program

// ------ Compliant Program (093_c.cpp)
// Context: Assign priorities to tasks
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <utility>

namespace prio_rule_093 {

static int clip(int p) {
    if (p < 0) { return 0; }
    if (p > 255) { return 255; }
    return p;
}

static void set_task_priority(int task_id, int prio) {
    std::cout << "task" << task_id << "=prio" << clip(prio) << std::endl;
}

static void batch(const std::vector<std::pair<int,int>>& pairs) {
    for (auto pr : pairs) { set_task_priority(pr.first, pr.second); }
}

} // namespace prio_rule_093

int main() {
    using namespace prio_rule_093;
    std::vector<std::pair<int,int>> pairs = {{5,10},{2,-5},{9,999}};
    batch(pairs);
    return 0;
}
