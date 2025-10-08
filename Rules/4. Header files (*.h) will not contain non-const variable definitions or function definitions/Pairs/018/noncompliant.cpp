// ------ Non-Compliant
// Seed: Non-compliant header: int block_size = 256;   // Compliant header: extern int block_size;
// Context: Demo showing a header that incorrectly defines a non-const global block size and a non-inline helper.
// Provenance: StackOverflow guidance on 'extern' vs definitions in headers; cppreference One Definition Rule (ODR).
// Violation: Header-like region contains a non-const global definition and a non-inline function definition (violates MISRA C++ Rule 8-5-2).

#include <iostream>
#include <vector>
#include <numeric>
#include <thread>
#include <chrono>

// ------------------- bad_header.h (inlined here for demo) -------------------
// NON-COMPLIANT: header contains definitions (violates Rule 8-5-2)
//
// Seed (must appear in header): int block_size = 256;
int block_size = 256; // NON-COMPLIANT: non-const global defined in header

// NON-COMPLIANT: non-inline function definition in header
int fill_block(std::vector<int> &out, int seed) {
    out.clear();
    out.reserve(std::min(block_size, 16)); // limit for demo
    for (int i = 0; i < std::min(block_size, 16); ++i) {
        out.push_back((seed + i) & 0xFF);
    }
    int sum = std::accumulate(out.begin(), out.end(), 0);
    std::cout << "[NC] fill_block: produced " << out.size() << " elements sum=" << sum << " block_size=" << block_size << '\n';
    return sum;
}
// ---------------------------------------------------------------------------

int main() {
    std::vector<int> data;
    int s = fill_block(data, 7);
    std::cout << "[NC] result sum=" << s << " data0=" << (data.empty() ? -1 : data[0]) << '\n';
    std::this_thread::sleep_for(std::chrono::milliseconds(5));
    return 0;
}