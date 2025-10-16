// ------ Compliant
// Seed: Non-compliant: unsigned taskId = 1u, taskPriority = 5u;   // Compliant: unsigned taskId = 1u; unsigned taskPriority = 5u;
// Context: Task identifier and priority for an onboard RTOS scheduler in a DRDO system.
// Violation: Multiple variables declared in one statement (MISRA C++:2008 Rule 8-0-1).
// Source: MathWorks / Polyspace — MISRA C++:2008 Rule 8-0-1.  [oai_citation:2‡MathWorks](https://es.mathworks.com/help///bugfinder/ref/misrac2008rule801.html?utm_source=chatgpt.com)

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <thread>
#include <chrono>
#include <fstream>
#include <sstream>
#include <iomanip>

struct Task {
    unsigned id;
    unsigned priority;
    Task(unsigned i = 0u, unsigned p = 0u) : id(i), priority(p) {}
};

// Simple scheduler: higher priority value => earlier execution
struct TaskCompare {
    bool operator()(const Task &a, const Task &b) const {
        return a.priority < b.priority;
    }
};

// Compliant: declare each variable on its own line (single init-declarator per declaration)
void scheduler_register_C(std::priority_queue<Task, std::vector<Task>, TaskCompare> &pq,
                           const std::string &logpath = "sched_c.log") {
    unsigned taskId = 1u;
    unsigned taskPriority = 5u;
    // (compliant: split declarations so each init-declarator-list has a single declarator)

    // deterministic registration of a few tasks
    for (unsigned i = 0; i < 6u; ++i) {
        // vary priority deterministically
        taskId = i + 1u;
        taskPriority = static_cast<unsigned>((i % 3u) + 1u);
        pq.emplace(taskId, taskPriority);

        // log registration
        std::ofstream out(logpath, std::ios::app);
        if (out) {
            out << "[C] Registered task id=" << taskId << " prio=" << taskPriority << '\n';
            out.close();
        } else {
            std::cerr << "[C] Failed to open log\n";
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
}

void scheduler_run_C(std::priority_queue<Task, std::vector<Task>, TaskCompare> &pq) {
    std::cout << "[C] Running scheduler...\n";
    while (!pq.empty()) {
        Task t = pq.top(); pq.pop();
        std::cout << "[C] Executing task id=" << t.id << " prio=" << t.priority << '\n';
        // deterministic short processing
        std::this_thread::sleep_for(std::chrono::milliseconds(8));
    }
}

int main() {
    std::priority_queue<Task, std::vector<Task>, TaskCompare> pq;
    scheduler_register_C(pq);
    scheduler_run_C(pq);
    return 0;
}