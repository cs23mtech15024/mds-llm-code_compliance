// Context: RFID reader timeout configuration

// -------- Non-Compliant Program (prog_036_nc.cpp)
// Context: RFID reader timeout behavior
#include <iostream>
#include "seedNC.h" // seed036_timeout_ms, seed036_should_retry()

namespace rfid_nc {

int simulate_attempts(int times[], std::size_t n) { // NC: array decay
    int retries = 0;
    for (std::size_t i = 0; i < n; ++i) {
        bool retry = seed036_should_retry(times[i]); // header fn (NC)
        std::cout << "elapsed=" << times[i]
                  << " retry=" << (retry ? "Y" : "N") << "\n";
        if (retry) ++retries;
    }
    return retries;
}

int sum(int arr[], std::size_t n) { // NC
    int s = 0;
    for (std::size_t i = 0; i < n; ++i) s += arr[i];
    return s;
}

} // namespace rfid_nc

int main() {
    using namespace rfid_nc;
    int t[5] = {50,100,200,260,300};
    int r = simulate_attempts(t,5);
    std::cout << "retries=" << r << " sum=" << sum(t,5) << "\n";
    return 0;
}
