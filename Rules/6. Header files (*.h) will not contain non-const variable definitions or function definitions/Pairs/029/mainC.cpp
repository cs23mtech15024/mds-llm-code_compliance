// Context: Database connection pool size header

// -------- Compliant Program (prog_029_c.cpp)
// Context: Database connection pool — COMPLIANT
#include <iostream>
#include "seedC.h"

// Definitions
int seed029_pool_size = 16;
int seed029_max_clients() { return seed029_pool_size - 2; }

namespace db_c {

template <std::size_t N>
void simulate(const int (&req)[N]) {
    for (std::size_t i = 0; i < N; ++i) {
        int possible = seed029_max_clients();
        std::cout << "req=" << req[i]
                  << " max=" << possible
                  << " served=" << ((req[i] <= possible) ? req[i] : possible)
                  << "\n";
    }
}

template <std::size_t N>
int sum(const int (&arr)[N]) {
    int s = 0;
    for (auto v : arr) s += v;
    return s;
}

} // namespace db_c

int main() {
    using namespace db_c;
    const int req[4] = {5,10,20,8};
    simulate(req);
    std::cout << "sum=" << sum(req) << "\n";
    return 0;
}
