// Context: Decimation factor setter — Expanded program

// ------ Non-Compliant Program (069_nc.cpp)
// Context: Choose integer decimation factor
// MISRA: Identifiers must not begin with '_'
// NC: variable begins with '_'
#include <iostream>
#include <vector>

namespace _dec_rule_069 {

static int _clipF(int f) {
    if (f < 1) { return 1; }
    if (f > 64) { return 64; }
    return f;
}

static void _set(int &_decim_factor, int v) { // NC
    _decim_factor = _clipF(v);
}

static void _demo(const std::vector<int>& _f) {
    int _decim_factor = 4;
    for (int v : _f) {
        _set(_decim_factor, v);
        std::cout << "decim=" << _decim_factor << std::endl;
    }
}

} // namespace _dec_rule_069

int main() {
    using namespace _dec_rule_069;
    std::vector<int> f = {4, 0, 100};
    _demo(f);
    return 0;
}
