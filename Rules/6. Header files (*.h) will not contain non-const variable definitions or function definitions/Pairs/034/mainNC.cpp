// Context: Audio equalizer preset header

// -------- Non-Compliant Program (prog_034_nc.cpp)
// Context: Audio equalizer preset
#include <iostream>
#include "seedNC.h" // seed034_bass, seed034_treble, seed034_eq_profile()

namespace eq_nc {

int clamp(int v) {
    return (v < 0) ? 0 : v;
}

void process(int samples[], std::size_t n) { // NC
    for (std::size_t i = 0; i < n; ++i) {
        int adj = seed034_eq_profile(clamp(samples[i]));
        std::cout << "in=" << samples[i]
                  << " adj=" << adj
                  << " bass=" << seed034_bass
                  << " treb=" << seed034_treble << "\n";
    }
}

int sum(int arr[], std::size_t n) { // NC
    int s = 0;
    for (std::size_t i = 0; i < n; ++i) s += arr[i];
    return s;
}

} // namespace eq_nc

int main() {
    using namespace eq_nc;
    int s[5] = {10,20,30,40,50};
    process(s,5);
    std::cout << "sum=" << sum(s,5) << "\n";
    return 0;
}
