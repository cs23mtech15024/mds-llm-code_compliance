// Context: Median filter window size — Expanded program

// ------ Compliant Program (051_c.cpp)
// Context: Median filter window selection
// C: no identifiers begin with '_'
#include <algorithm>
#include <iostream>
#include <vector>
#include <iomanip>

namespace med_rule_051 {

static int clipOdd(int v) {
    if (v < 1) { v = 1; }
    if ((v % 2) == 0) { v += 1; }
    if (v > 99) { v = 99; }
    return v;
}

static int median(const std::vector<int>& a) {
    std::vector<int> b = a;
    std::sort(b.begin(), b.end());
    return b[b.size() / 2U];
}

static void run(int window_size, const std::vector<int>& samples) {
    int w = clipOdd(window_size);
    for (std::size_t i = 0; i < samples.size(); ++i) {
        std::vector<int> win;
        for (int j = static_cast<int>(i) - (w/2); j <= static_cast<int>(i) + (w/2); ++j) {
            if (j >= 0 && j < static_cast<int>(samples.size())) { win.push_back(samples[static_cast<std::size_t>(j)]); }
        }
        if (!win.empty()) {
            std::cout << "i=" << i << " med=" << median(win) << std::endl;
        }
    }
}

} // namespace med_rule_051

int main() {
    using namespace med_rule_051;
    std::vector<int> s = {5, 7, 100, 8, 9, 3, 4, 6, 7};
    run(5, s);
    return 0;
}
