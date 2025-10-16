// ------ Compliant
// Seed: Non-compliant header: int block_size = 256;   // Compliant header: extern int block_size;
// Context: Header contains only declarations; definitions moved into implementation.
// Provenance: StackOverflow guidance on 'extern' vs definitions in headers; cppreference One Definition Rule (ODR).
// Compliance: Header-like region contains only declarations (extern and prototype); definitions are in the implementation area.

#include <iostream>
#include <vector>
#include <numeric>
#include <thread>
#include <chrono>

// ------------------- good_header.h (inlined here for demo) -------------------
// COMPLIANT: header contains only declarations (no non-const definitions)
//
// Seed (header declaration): extern int block_size;
extern int block_size; // declaration only

// Function prototype only (no definition in header)
int fill_block(std::vector<int> &out, int seed);
// ---------------------------------------------------------------------------

// Implementation section: definitions moved out of header area (compliant)
int block_size = 256; // COMPLIANT: definition in implementation file

int fill_block(std::vector<int> &out, int seed) {
    out.clear();
    out.reserve(std::min(block_size, 16)); // limit for demo
    for (int i = 0; i < std::min(block_size, 16); ++i) {
        out.push_back((seed + i) & 0xFF);
    }
    int sum = std::accumulate(out.begin(), out.end(), 0);
    std::cout << "[C] fill_block: produced " << out.size() << " elements sum=" << sum << " block_size=" << block_size << '\n';
    return sum;
}

int main() {
    std::vector<int> data;
    int s = fill_block(data, 7);
    std::cout << "[C] result sum=" << s << " data0=" << (data.empty() ? -1 : data[0]) << '\n';
    std::this_thread::sleep_for(std::chrono::milliseconds(5));
    return 0;
}