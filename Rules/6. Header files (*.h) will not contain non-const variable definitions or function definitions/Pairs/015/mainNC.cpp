// Context: Printer spooler job queue defaults

// -------- Non-Compliant Program (prog_015_nc.cpp)
// Context: Printer spooler defaults
#include <iostream>
#include "seedNC.h" // seed015_default_queue, seed015_enqueue_limit()

namespace spool_nc {

void print_limits() {
    std::cout << "default_queue=" << seed015_default_queue
              << " enqueue_limit=" << seed015_enqueue_limit() << "\n";
}

int push_jobs(int jobs[], std::size_t n) { // NC decay
    int accepted = 0;
    int limit = seed015_enqueue_limit();
    for (std::size_t i = 0; i < n; ++i) {
        if (accepted < limit) ++accepted;
    }
    return accepted;
}

} // namespace spool_nc

int main() {
    using namespace spool_nc;
    print_limits();
    int jobs[6] = {1,1,1,1,1,1};
    std::cout << "accepted=" << push_jobs(jobs,6) << "\n";
    return 0;
}
