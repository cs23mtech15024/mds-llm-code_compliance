// Context: Database connection pool size header

// -------- Non-Compliant Program (prog_029_nc.cpp)
// Context: Database connection pool
#include <iostream>
#include "seedNC.h" // seed029_pool_size, seed029_max_clients()

namespace db_nc {

void simulate(int req[], std::size_t n) { // NC
    for (std::size_t i = 0; i < n; ++i) {
        int possible = seed029_max_clients();
        std::cout << "req=" << req[i]
                  << " max=" << possible
                  << " served=" << ((req[i] <= possible) ? req[i] : possible)
                  << "\n";
    }
}

int sum(int arr[], std::size_t n) {
    int s = 0;
    for (std::size_t i = 0; i < n; ++i) s += arr[i];
    return s;
}

} // namespace db_nc

int main() {
    using namespace db_nc;
    int reqs[4] = {5,10,20,8};
    simulate(reqs,4);
    std::cout << "sum=" << sum(reqs,4) << "\n";
    return 0;
}
