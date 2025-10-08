// ------ Compliant
// Seed: Non-compliant header: int buffer_size = 1024;   // Compliant header: extern int buffer_size;
// Context: Header contains only declarations; definitions moved into implementation.
// Provenance: cppreference (ODR / header best practices) and common StackOverflow examples on multiple-definition errors.
// Compliance: Header-like region contains only declarations (extern + prototype); the global and helper definition are in implementation.

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>

// ------------------- good_header.h (inlined here for demo) -------------------
// COMPLIANT: header contains only declarations (no non-const definitions)
//
// Seed (header declaration): extern int buffer_size;
extern int buffer_size; // declaration only

// Function prototype only (no definition in header)
int fill_buffer(std::vector<int> &buf, int seed);
// ---------------------------------------------------------------------------

// Implementation section: definitions moved out of header area (compliant)
int buffer_size = 1024; // COMPLIANT: definition in implementation

int fill_buffer(std::vector<int> &buf, int seed) {
    buf.clear();
    buf.reserve(buffer_size);
    for (int i = 0; i < buffer_size && i < 16; ++i) { // limit for demo
        buf.push_back((seed + i) % 256);
    }
    std::cout << "[C] fill_buffer produced " << buf.size() << " elements (buffer_size=" << buffer_size << ")\n";
    return static_cast<int>(buf.size());
}

int main() {
    std::vector<int> buf;
    int produced = fill_buffer(buf, 5);
    std::cout << "[C] produced=" << produced << " final buf[0]=" << (buf.empty() ? -1 : buf[0]) << '\n';
    std::this_thread::sleep_for(std::chrono::milliseconds(5));
    return 0;
}