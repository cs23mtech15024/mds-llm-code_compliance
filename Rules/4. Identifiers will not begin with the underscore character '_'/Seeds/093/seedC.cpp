// Context: Task priority assignment

// Seed 093 — C: function and parameters without underscore prefix
#include <iostream>
void set_task_priority(int task_id, int prio) { // C
    std::cout << "task" << task_id << "=prio" << prio << "\n";
}
int main(){
    set_task_priority(5, 10);
    return 0;
}