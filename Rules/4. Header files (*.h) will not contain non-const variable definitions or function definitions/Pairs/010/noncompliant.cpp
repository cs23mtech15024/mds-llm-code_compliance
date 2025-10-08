// ------ Non-Compliant
// Seed: Non-compliant header: std::vector<int> cache = {1,2};   // Compliant header: extern std::vector<int> cache;
// Context: Adapted demo showing a header that incorrectly defines a non-const container and a non-inline function.
// Provenance:
//   - StackOverflow Q#1433204: extern usage and sharing globals. https://stackoverflow.com/questions/1433204/how-do-i-use-extern-to-share-variables-between-source-files.  
//   - cppreference: One Definition Rule / Definitions and ODR. https://en.cppreference.com/w/cpp/language/definition.  
//   - PVS-Studio guidance on definitions in headers (header best practices).
// Violation: Header contains a non-const global definition and a non-inline function definition (violates MISRA C++ Rule 8-5-2).

#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <chrono>
#include <numeric>

// ------------------- bad_header.h (inlined here for demo) -------------------
// NON-COMPLIANT: header contains definitions (violates Rule 8-5-2)
//
// Seed (must appear in header): std::vector<int> cache = {1,2};
std::vector<int> cache = {1, 2}; // NON-COMPLIANT: non-const container defined in header

// NON-COMPLIANT: non-inline function definition in header
int sum_and_report_cache() {
    int s = std::accumulate(cache.begin(), cache.end(), 0);
    std::cout << "[NC] sum_and_report_cache => sum=" << s << " size=" << cache.size() << '\n';
    return s;
}
// ---------------------------------------------------------------------------

int main() {
    // mutate cache deterministically
    cache.push_back(3);
    cache.push_back(5);
    int total = sum_and_report_cache();
    std::this_thread::sleep_for(std::chrono::milliseconds(5));
    std::cout << "[NC] final total=" << total << " cache0=" << (cache.empty() ? -1 : cache[0]) << '\n';
    return 0;
}