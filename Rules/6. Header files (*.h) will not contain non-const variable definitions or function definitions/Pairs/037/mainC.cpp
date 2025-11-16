// Context: Industrial PLC valve timing parameters

// -------- Compliant Program (prog_037_c.cpp)
// Context: PLC valve timing — COMPLIANT
#include <iostream>
#include "seedC.h"

// Definitions
int seed037_open_ms = 40;
int seed037_close_ms = 30;
int seed037_cycle_time() { return seed037_open_ms + seed037_close_ms; }

namespace plc_c {

template <std::size_t N>
void run_cycle(const int (&vals)[N]) {
    for (std::size_t i = 0; i < N; ++i) {
        int total = seed037_cycle_time();
        std::cout << "cycle=" << i
                  << " open=" << seed037_open_ms
                  << " close=" << seed037_close_ms
                  << " total=" << total << "\n";
    }
}

template <std::size_t N>
int sum(const int (&arr)[N]) {
    int s = 0; for (auto v : arr) s += v; return s;
}

} // namespace plc_c

int main() {
    using namespace plc_c;
    const int v[3] = {1,1,1};
    run_cycle(v);
    std::cout << "sum=" << sum(v) << "\n";
    return 0;
}
