// Context: Task priority assignment — Expanded program

// ------ Non-Compliant Program (093_nc.cpp)
// Context: Assign priorities to tasks
// MISRA: Identifiers must not begin with '_'
// NC: function and parameters begin with '_'
#include <iostream>
#include <vector>
#include <utility>

namespace _prio_rule_093 {

static int _clip(int p) {
    if (p < 0) { return 0; }
    if (p > 255) { return 255; }
    return p;
}

static void _set_task_priority(int _task_id, int _prio) { // NC
    std::cout << "task" << _task_id << "=prio" << _clip(_prio) << std::endl;
}

static void _batch(const std::vector<std::pair<int,int>>& _pairs) {
    for (auto pr : _pairs) { _set_task_priority(pr.first, pr.second); }
}

} // namespace _prio_rule_093

int main() {
    using namespace _prio_rule_093;
    std::vector<std::pair<int,int>> pairs = {{5,10},{2,-5},{9,999}};
    _batch(pairs);
    return 0;
}
