// Context: Image processing threshold parameter — Expanded program

// ------ Non-Compliant Program (004_nc.cpp)
// Context: Binary thresholding
// NC: parameter and helpers use leading '_'
#include <iostream>
#include <vector>

namespace _img_rule_004 {

static int _clip255(int v) {
    if (v < 0) { return 0; }
    if (v > 255) { return 255; }
    return v;
}

static int _apply_threshold(int _threshold, int value) {
    return (value > _threshold) ? 255 : 0;
}

static void _process(const std::vector<int> &_pixels, int _threshold) {
    for (int p : _pixels) {
        int out = _apply_threshold(_threshold, _clip255(p));
        std::cout << out << std::endl;
    }
}

} // namespace _img_rule_004

int main() {
    using namespace _img_rule_004;
    std::vector<int> px = {0, 100, 128, 200, 260};
    _process(px, 128);
    return 0;
}
