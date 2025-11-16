// Context: Filesystem path length limits header

// -------- Compliant Program (prog_017_c.cpp)
// Context: Filesystem path length limits — COMPLIANT
#include <iostream>
#include <string>
#include "seedC.h"  // extern seed017_max_path, seed017_too_long()

// Definitions
int seed017_max_path = 260;
bool seed017_too_long(const char* p) {
    int len = 0; while (p && p[len]) ++len; return len > seed017_max_path;
}

namespace fs_c {

int length_of(const char* p) {
    int len = 0; while (p && p[len]) ++len; return len;
}

template <std::size_t N>
void check_paths(const char* const (&paths)[N]) {
    for (std::size_t i = 0; i < N; ++i) {
        const char* p = paths[i];
        bool too_long = seed017_too_long(p);
        std::cout << "path='" << p << "' len=" << length_of(p)
                  << " too_long=" << (too_long ? "Y" : "N") << "\n";
    }
}

template <std::size_t N>
int longest_len(const char* const (&paths)[N]) {
    int max = 0;
    for (auto p : paths) {
        int l = length_of(p);
        if (l > max) max = l;
    }
    return max;
}

} // namespace fs_c

int main() {
    using namespace fs_c;
    const char* arr[3] = {"/usr/bin","/home/user/documents","/this/is/a/very/long/path/example"};
    check_paths(arr);
    std::cout << "max_len=" << longest_len(arr) << "\n";
    return 0;
}
