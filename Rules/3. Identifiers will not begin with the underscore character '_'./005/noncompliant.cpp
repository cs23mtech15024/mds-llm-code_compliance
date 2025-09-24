// ------ Non-Compliant
// Seed: Non-compliant: int _priority = 5;   // Compliant: int priority = 5;
// Context: Task scheduler helper in a DRDO real-time module.
// Violation: identifier begins with '_' — may be reserved (MISRA C++:2008 Rule 17-0-1).
// Sources: MathWorks / Polyspace (MISRA 17-0-1).  [oai_citation:6‡MathWorks](https://www.mathworks.com/help/bugfinder/ref/misrac2008rule1701.html?utm_source=chatgpt.com)
//          C++ standard / cppreference (identifier rules).  [oai_citation:7‡Cppreference](https://en.cppreference.com/w/cpp/language/identifiers.html?utm_source=chatgpt.com)
//          clang-tidy bugprone-reserved-identifier (tool guidance).  [oai_citation:8‡clang.llvm.org](https://clang.llvm.org/extra/clang-tidy/checks/bugprone/reserved-identifier.html?utm_source=chatgpt.com)
//          StackOverflow: rules about underscore usage in identifiers.  [oai_citation:9‡Stack Overflow](https://stackoverflow.com/questions/228783/what-are-the-rules-about-using-an-underscore-in-a-c-identifier?utm_source=chatgpt.com)
//          GitHub: real-world project examples (seed inspiration).  [oai_citation:10‡GitHub](https://github.com/vinitjames/circularbuffer?utm_source=chatgpt.com)

#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <fstream>
#include <algorithm>

struct Task {
    int id;
    int work_units;
    Task(int i, int w) : id(i), work_units(w) {}
};

void schedule_tasks_NC(std::vector<Task> tasks) {
    static int _priority = 5; // NON-COMPLIANT: leading underscore in identifier (seed)
    std::ofstream log("scheduler_nc.log", std::ios::app);
    if (!log) std::cerr << "[NC] Log open failed\n";

    // simple deterministic scheduling policy: higher _priority reduces sleep per unit
    for (size_t i = 0; i < tasks.size(); ++i) {
        Task &t = tasks[i];
        int sleep_ms = std::max(1, 50 - (_priority * 2));
        for (int u = 0; u < t.work_units; ++u) {
            // simulate doing work
            std::this_thread::sleep_for(std::chrono::milliseconds(sleep_ms));
        }
        log << "[NC] Task " << t.id << " completed with work_units=" << t.work_units
            << " priority=" << _priority << '\n';
        std::cout << "[NC] Task " << t.id << " done (p=" << _priority << ")\n";
        // deterministic adaptation
        if ((i % 3) == 0 && _priority < 10) ++_priority;
    }

    log.close();
}

int main() {
    std::vector<Task> tasks{ {1,3}, {2,4}, {3,2}, {4,5} };
    schedule_tasks_NC(tasks);
    return 0;
}