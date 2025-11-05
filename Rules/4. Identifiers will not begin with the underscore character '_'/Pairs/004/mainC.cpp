// Context: Image processing threshold parameter — Expanded program

// ------ Compliant Program (004_c.cpp)
// Context: Binary thresholding
// C: no leading underscores in identifiers
#include <iostream>
#include <vector>

namespace img_rule_004 {

static int clip255(int v) {
    if (v < 0) { return 0; }
    if (v > 255) { return 255; }
    return v;
}

static int apply_threshold(int threshold, int value) {
    return (value > threshold) ? 255 : 0;
}

static void process(const std::vector<int> &pixels, int threshold) {
    for (int p : pixels) {
        int out = apply_threshold(threshold, clip255(p));
        std::cout << out << std::endl;
    }
}

} // namespace img_rule_004

int main() {
    using namespace img_rule_004;
    std::vector<int> px = {0, 100, 128, 200, 260};
    process(px, 128);
    return 0;
}
