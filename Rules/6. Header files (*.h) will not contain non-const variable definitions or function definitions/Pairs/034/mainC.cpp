// Context: Audio equalizer preset header

// -------- Compliant Program (prog_034_c.cpp)
// Context: Audio equalizer preset — COMPLIANT
#include <iostream>
#include "seedC.h"

// Definitions
int seed034_bass = 5;
int seed034_treble = 7;
int seed034_eq_profile(int x) { return x + seed034_bass - seed034_treble; }

namespace eq_c {

int clamp(int v) { return (v < 0) ? 0 : v; }

template <std::size_t N>
void process(const int (&samples)[N]) {
    for (std::size_t i = 0; i < N; ++i) {
        int adj = seed034_eq_profile(clamp(samples[i]));
        std::cout << "in=" << samples[i]
                  << " adj=" << adj
                  << " bass=" << seed034_bass
                  << " treb=" << seed034_treble << "\n";
    }
}

template <std::size_t N>
int sum(const int (&arr)[N]) {
    int s = 0;
    for (auto v : arr) s += v;
    return s;
}

} // namespace eq_c

int main() {
    using namespace eq_c;
    const int s[5] = {10,20,30,40,50};
    process(s);
    std::cout << "sum=" << sum(s) << "\n";
    return 0;
}
