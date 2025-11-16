// Context: Industrial PLC valve timing parameters

// -------- Non-Compliant Program (prog_037_nc.cpp)
// Context: PLC valve timing
#include <iostream>
#include "seedNC.h" // seed037_open_ms, seed037_close_ms, seed037_cycle_time()

namespace plc_nc {

void run_cycle(int vals[], std::size_t n) { // NC decay
    for (std::size_t i = 0; i < n; ++i) {
        int total = seed037_cycle_time();
        std::cout << "cycle=" << i
                  << " open=" << seed037_open_ms
                  << " close=" << seed037_close_ms
                  << " total=" << total << "\n";
    }
}

int sum(int arr[], std::size_t n) { // NC
    int s = 0; for (std::size_t i = 0; i < n; ++i) s += arr[i]; return s;
}

} // namespace plc_nc

int main() {
    using namespace plc_nc;
    int v[3] = {1,1,1};
    run_cycle(v,3);
    std::cout << "sum=" << sum(v,3) << "\n";
    return 0;
}
