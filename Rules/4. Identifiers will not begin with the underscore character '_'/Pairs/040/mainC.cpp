// Context: Bitrate calculator for streaming — Expanded program

// ------ Compliant Program (040_c.cpp)
// Context: width*height*fps bitrate (toy)
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace br_rule_040 {

static long safeMul(long a, long b) {
    const long LIM = 2000000000L;
    long r = a * b;
    if (r < 0) { return 0; }
    if (r > LIM) { return LIM; }
    return r;
}

static long bitrate(int width, int height, int fps) {
    long p1 = safeMul(static_cast<long>(width), static_cast<long>(height));
    long p2 = safeMul(p1, static_cast<long>(fps));
    return p2;
}

static void show(const std::vector<std::tuple<int,int,int>> &cases) {
    for (const auto &t : cases) {
        int width = std::get<0>(t);
        int height = std::get<1>(t);
        int fps = std::get<2>(t);
        std::cout << "bitrate=" << bitrate(width, height, fps) << std::endl;
    }
}

} // namespace br_rule_040

int main() {
    using namespace br_rule_040;
    std::vector<std::tuple<int,int,int>> cases;
    cases.emplace_back(1920,1080,30);
    cases.emplace_back(1280,720,60);
    cases.emplace_back(3840,2160,120);
    show(cases);
    return 0;
}
