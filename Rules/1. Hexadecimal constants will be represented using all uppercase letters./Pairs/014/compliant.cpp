// ------ Compliant
// Pair 14 — Seed: 1u -> 1U
// Context: Task ID for scheduling in DRDO onboard real-time operating system.
// Violation: lowercase 'u' suffix may impede static analysis.
// Source: MISRA C++ Rule 2-13-4 (literal suffixes shall be upper case).

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstdint>

enum class TaskID : unsigned {
    NAV_UPDATE = 0U,
    SENSOR_READ = 1U,
    TELEMETRY_SEND = 2U
};

struct Task {
    TaskID id;
    unsigned priority;
    std::string name;
};

class Scheduler_C {
public:
    Scheduler_C() {
        // Seed usage corrected: uppercase 'U'
        tasks.push_back({TaskID::NAV_UPDATE, 1U, "Navigation Update"});
        tasks.push_back({TaskID::SENSOR_READ, 2U,   "Sensor Read"});
        tasks.push_back({TaskID::TELEMETRY_SEND, 1U, "Telemetry Send"});
    }

    void runOnce() {
        // process up to 1U high-priority task per cycle (C)
        unsigned processed = 0U; // C
        std::queue<Task> q;
        for (const auto &t : tasks) q.push(t);

        while (!q.empty() && processed < 1U) { // C
            Task t = q.front(); q.pop();
            executeTask(t);
            ++processed;
        }

        std::cout << "[C] Processed " << processed << " task(s) this cycle\n";
    }

private:
    void executeTask(const Task &t) {
        std::cout << "[C] Executing: " << t.name << " (priority=" << t.priority << ")\n";
    }

    std::vector<Task> tasks;
};

int main() {
    Scheduler_C sched;
    // simulate a few cycles
    for (int i = 0; i < 3; ++i) {
        sched.runOnce();
    }
    return 0;
}