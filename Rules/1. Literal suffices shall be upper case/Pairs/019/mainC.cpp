// ------ Compliant (Seed 019)
// Context: Computer Vision — simple histogram equalization on a tiny grayscale buffer.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Fixes: all literal suffixes changed to uppercase F, U, and L.

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

static float normalize(int v, int vmin, int vmax, float eps) {
    const float denom = static_cast<float>(vmax - vmin) + eps; // eps may be 1E-5F (compliant)
    return (static_cast<float>(v - vmin)) / denom;
}

int main() {
    // Grayscale pixels (0..255)
    const std::vector<int> input {12, 64, 128, 128, 240};
    std::vector<int> output(input.size(), 0);

    // Compliant literal suffix usage:
    const unsigned MAXV = 255U;   // compliant
    const long     PASS = 1L;     // compliant
    const float    EPS  = 1E-5F;  // compliant

    (void)PASS; // just to show a loop count in a real pipeline

    const auto [minIt, maxIt] = std::minmax_element(input.begin(), input.end());
    const int vmin = *minIt;
    const int vmax = *maxIt;

    for (std::size_t i = 0; i < input.size(); ++i) {
        float n = normalize(input[i], vmin, vmax, EPS);
        // Equalize and stretch to [0, MAXV]
        int eq = static_cast<int>(n * static_cast<float>(MAXV) + 0.5F); // compliant
        if (eq < 0) { eq = 0; }
        if (eq > static_cast<int>(MAXV)) { eq = static_cast<int>(MAXV); }
        output[i] = eq;
    }

    std::cout << "Equalized:";
    for (int p : output) {
        std::cout << ' ' << p;
    }
    std::cout << '\n';
    return 0;
}