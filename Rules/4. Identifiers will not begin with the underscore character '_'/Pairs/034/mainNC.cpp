// Context: Error code validator — Expanded program

// ------ Non-Compliant Program (034_nc.cpp)
// Context: Negative means error
// MISRA: Identifiers must not begin with '_'
// NC: function begins with '_'
#include <iostream>
#include <vector>
#include <string>

namespace _err_rule_034 {

static bool _is_error(int code) { // NC
    return code < 0;
}

static void _report(const std::vector<int> &_codes) {
    for (int c : _codes) {
        std::cout << "code=" << c << " error=" << _is_error(c) << std::endl;
    }
}

static std::vector<int> _parse(const std::vector<std::string> &_s) {
    std::vector<int> out;
    out.reserve(_s.size());
    for (const auto &x : _s) {
        try { out.push_back(std::stoi(x)); }
        catch (...) { out.push_back(-1); }
    }
    return out;
}

} // namespace _err_rule_034

int main() {
    using namespace _err_rule_034;
    std::vector<std::string> raw = {"0","-1","17","oops"};
    auto codes = _parse(raw);
    _report(codes);
    return 0;
}
