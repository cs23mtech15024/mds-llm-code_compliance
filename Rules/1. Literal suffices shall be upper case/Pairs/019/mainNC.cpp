// ------ Non-Compliant (Seed 019)
// Context: Computer Vision — simple histogram equalization on a tiny grayscale buffer.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violations: lowercase 'f', 'u', and 'l' suffixes used in constants.

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

static float normalize(int v, int vmin, int vmax, float eps) {
    const float denom = static_cast<float>(vmax - vmin) + eps; // eps may be 1e-5f (non-compliant)
    return (static_cast<float>(v - vmin)) / denom;
}

int main() {
    // Grayscale pixels (0..255)
    const std::vector<int> input {12, 64, 128, 128, 240};
    std::vector<int> output(input.size(), 0);

    // Non-compliant literal suffix usage here:
    const unsigned MAXV = 255u;   // should be 255U
    const long     PASS = 1l;     // should be 1L
    const float    EPS  = 1e-5f;  // should be 1e-5F

    (void)PASS; // just to show a loop count in a real pipeline

    const auto [minIt, maxIt] = std::minmax_element(input.begin(), input.end());
    const int vmin = *minIt;
    const int vmax = *maxIt;

    for (std::size_t i = 0; i < input.size(); ++i) {
        float n = normalize(input[i], vmin, vmax, EPS);
        // Equalize and stretch to [0, MAXV]
        int eq = static_cast<int>(n * static_cast<float>(MAXV) + 0.5f); // 0.5f non-compliant
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