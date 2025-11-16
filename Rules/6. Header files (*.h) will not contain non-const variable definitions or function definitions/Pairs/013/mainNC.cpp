// Context: Filesystem cache parameters header

// -------- Non-Compliant Program (prog_013_nc.cpp)
// Context: Filesystem cache parameters
#include <iostream>
#include <cstddef>
#include "seedNC.h" // seed013_cache_size, seed013_should_evict()

namespace fs_nc {

void status(std::size_t used) {
    std::cout << "cache_size=" << seed013_cache_size << " used=" << used
              << " evict=" << (seed013_should_evict(used) ? "Y":"N") << "\n";
}

void simulate(std::size_t logs[], std::size_t n) { // NC decay
    for (std::size_t i = 0; i < n; ++i) status(logs[i]);
}

} // namespace fs_nc

int main() {
    using namespace fs_nc;
    std::size_t samples[4] = {1024,4096,5000,3000};
    simulate(samples,4);
    return 0;
}
