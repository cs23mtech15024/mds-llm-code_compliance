// Context: Bitrate calculator for streaming — Expanded program

// ------ Non-Compliant Program (040_nc.cpp)
// Context: width*height*fps bitrate (toy)
// MISRA: Identifiers must not begin with '_'
// NC: variables begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _br_rule_040 {

static long _safeMul(long a, long b) {
    const long LIM = 2000000000L;
    long r = a * b;
    if (r < 0) { return 0; }
    if (r > LIM) { return LIM; }
    return r;
}

static long _bitrate(int _width, int _height, int _fps) { // NC
    long p1 = _safeMul(static_cast<long>(_width), static_cast<long>(_height));
    long p2 = _safeMul(p1, static_cast<long>(_fps));
    return p2;
}

static void _show(const std::vector<std::tuple<int,int,int>> &_cases) {
    for (const auto &t : _cases) {
        int _width = std::get<0>(t);
        int _height = std::get<1>(t);
        int _fps = std::get<2>(t);
        std::cout << "bitrate=" << _bitrate(_width, _height, _fps) << std::endl;
    }
}

} // namespace _br_rule_040

int main() {
    using namespace _br_rule_040;
    std::vector<std::tuple<int,int,int>> cases;
    cases.emplace_back(1920,1080,30);
    cases.emplace_back(1280,720,60);
    cases.emplace_back(3840,2160,120);
    _show(cases);
    return 0;
}
