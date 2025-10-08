// ------ Non-Compliant
// Seed: Non-compliant header: int buffer_size = 1024;   // Compliant header: extern int buffer_size;
// Context: Adapted demo showing a header that incorrectly defines a non-const global buffer size and a helper function.
// Provenance: cppreference (ODR / header best practices) and common StackOverflow examples on multiple-definition errors.
// Violation: Header contains a non-const variable definition and a non-inline function definition (violates MISRA C++ Rule 8-5-2).

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>

// ------------------- bad_header.h (inlined here for demo) -------------------
// NON-COMPLIANT: header contains definitions (violation)
//
// Seed (must appear in header): int buffer_size = 1024;
int buffer_size = 1024; // NON-COMPLIANT: non-const global defined in header

// NON-COMPLIANT: non-inline helper function defined in header
int fill_buffer(std::vector<int> &buf, int seed) {
    buf.clear();
    buf.reserve(buffer_size);
    for (int i = 0; i < buffer_size && i < 16; ++i) { // limit for demo to keep memory small
        buf.push_back((seed + i) % 256);
    }
    std::cout << "[NC] fill_buffer produced " << buf.size() << " elements (buffer_size=" << buffer_size << ")\n";
    return static_cast<int>(buf.size());
}
// ---------------------------------------------------------------------------

int main() {
    std::vector<int> buf;
    int produced = fill_buffer(buf, 5);
    std::cout << "[NC] produced=" << produced << " final buf[0]=" << (buf.empty() ? -1 : buf[0]) << '\n';
    // deterministic short sleep to simulate work
    std::this_thread::sleep_for(std::chrono::milliseconds(5));
    return 0;
}