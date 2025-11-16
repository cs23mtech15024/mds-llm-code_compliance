// Context: Printer spooler job queue defaults

// -------- Compliant Program (prog_015_c.cpp)
// Context: Printer spooler defaults — COMPLIANT
#include <iostream>
#include "seedC.h" // extern seed015_default_queue, seed015_enqueue_limit()

// Definitions
int seed015_default_queue = 10;
int seed015_enqueue_limit() { return seed015_default_queue - 1; }

namespace spool_c {

void print_limits() {
    std::cout << "default_queue=" << seed015_default_queue
              << " enqueue_limit=" << seed015_enqueue_limit() << "\n";
}

template <std::size_t N>
int push_jobs(const int (&jobs)[N]) {
    int accepted = 0;
    int limit = seed015_enqueue_limit();
    for (std::size_t i = 0; i < N; ++i) {
        if (accepted < limit) ++accepted;
    }
    return accepted;
}

} // namespace spool_c

int main() {
    using namespace spool_c;
    print_limits();
    const int jobs[6] = {1,1,1,1,1,1};
    std::cout << "accepted=" << push_jobs(jobs) << "\n";
    return 0;
}
