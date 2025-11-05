// Context: Decimation factor setter — Expanded program

// ------ Compliant Program (069_c.cpp)
// Context: Choose integer decimation factor
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>

namespace dec_rule_069 {

static int clipF(int f) {
    if (f < 1) { return 1; }
    if (f > 64) { return 64; }
    return f;
}

static void set(int &decim_factor, int v) {
    decim_factor = clipF(v);
}

static void demo(const std::vector<int>& f) {
    int decim_factor = 4;
    for (int v : f) {
        set(decim_factor, v);
        std::cout << "decim=" << decim_factor << std::endl;
    }
}

} // namespace dec_rule_069

int main() {
    using namespace dec_rule_069;
    std::vector<int> f = {4, 0, 100};
    demo(f);
    return 0;
}
