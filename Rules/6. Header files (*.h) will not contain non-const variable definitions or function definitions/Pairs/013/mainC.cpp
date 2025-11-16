// Context: Filesystem cache parameters header

// -------- Compliant Program (prog_013_c.cpp)
// Context: Filesystem cache parameters — COMPLIANT
#include <iostream>
#include <cstddef>
#include "seedC.h" // extern seed013_cache_size, seed013_should_evict()

// Definitions
std::size_t seed013_cache_size = 4096;
bool seed013_should_evict(std::size_t used) { return used > seed013_cache_size; }

namespace fs_c {

template <std::size_t N>
void simulate(const std::size_t (&logs)[N]) {
    for (std::size_t i = 0; i < N; ++i) {
        std::cout << "cache_size=" << seed013_cache_size
                  << " used=" << logs[i]
                  << " evict=" << (seed013_should_evict(logs[i]) ? "Y":"N")
                  << "\n";
    }
}

} // namespace fs_c

int main() {
    using namespace fs_c;
    const std::size_t samples[4] = {1024,4096,5000,3000};
    simulate(samples);
    return 0;
}
