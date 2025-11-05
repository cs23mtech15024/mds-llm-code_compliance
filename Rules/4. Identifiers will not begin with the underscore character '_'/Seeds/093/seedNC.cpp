// Context: Task priority assignment

// Seed 093 — NC: function and parameter start with underscore
#include <iostream>
void _set_task_priority(int _task_id, int _prio) { // NC
    std::cout << "task" << _task_id << "=prio" << _prio << "\n";
}
int main(){
    _set_task_priority(5, 10);
    return 0;
}