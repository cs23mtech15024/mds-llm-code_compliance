// ------ Compliant
// Seed: Non-compliant header: std::vector<int> cache = {1,2};   // Compliant header: extern std::vector<int> cache;
// Context: Header contains only declarations; definitions moved into implementation.
// Provenance:
//   - StackOverflow Q#1433204: extern usage and sharing globals. https://stackoverflow.com/questions/1433204/how-do-i-use-extern-to-share-variables-between-source-files.  
//   - cppreference: One Definition Rule / Definitions and ODR. https://en.cppreference.com/w/cpp/language/definition.  
//   - PVS-Studio guidance on definitions in headers (header best practices).
// Compliance: Header-like region contains only declarations (extern + prototype); definitions moved to implementation.

#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <chrono>
#include <numeric>

// ------------------- good_header.h (inlined here for demo) -------------------
// COMPLIANT: header contains only declarations (no non-const definitions)
//
// Seed (header declaration): extern std::vector<int> cache;
extern std::vector<int> cache; // declaration only

// Function prototype only (no definition in header)
int sum_and_report_cache();
// ---------------------------------------------------------------------------

// Implementation section: definitions moved out of header area (compliant)
std::vector<int> cache = {1, 2}; // COMPLIANT: definition in implementation

int sum_and_report_cache() {
    int s = std::accumulate(cache.begin(), cache.end(), 0);
    std::cout << "[C] sum_and_report_cache => sum=" << s << " size=" << cache.size() << '\n';
    return s;
}

int main() {
    cache.push_back(3);
    cache.push_back(5);
    int total = sum_and_report_cache();
    std::this_thread::sleep_for(std::chrono::milliseconds(5));
    std::cout << "[C] final total=" << total << " cache0=" << (cache.empty() ? -1 : cache[0]) << '\n';
    return 0;
}