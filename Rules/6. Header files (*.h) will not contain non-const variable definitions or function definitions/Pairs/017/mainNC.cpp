// Context: Filesystem path length limits header

// -------- Non-Compliant Program (prog_017_nc.cpp)
// Context: Filesystem path length limits
#include <iostream>
#include <string>
#include "seedNC.h" // seed017_max_path, seed017_too_long()

namespace fs_nc {

int length_of(const char* p) {
    int len = 0; while (p && p[len]) ++len; return len;
}

void check_paths(const char* paths[], std::size_t n) { // NC decay
    for (std::size_t i = 0; i < n; ++i) {
        const char* p = paths[i];
        bool too_long = seed017_too_long(p);
        std::cout << "path='" << p << "' len=" << length_of(p)
                  << " too_long=" << (too_long ? "Y" : "N") << "\n";
    }
}

int longest_len(const char* paths[], std::size_t n) { // NC
    int max = 0;
    for (std::size_t i = 0; i < n; ++i) {
        int l = length_of(paths[i]);
        if (l > max) max = l;
    }
    return max;
}

} // namespace fs_nc

int main() {
    using namespace fs_nc;
    const char* arr[3] = {"/usr/bin","/home/user/documents","/this/is/a/very/long/path/example"};
    check_paths(arr, 3);
    std::cout << "max_len=" << longest_len(arr,3) << "\n";
    return 0;
}
