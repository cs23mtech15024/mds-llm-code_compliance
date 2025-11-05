// Context: Error code validator — Expanded program

// ------ Compliant Program (034_c.cpp)
// Context: Negative means error
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <string>

namespace err_rule_034 {

static bool is_error(int code) {
    return code < 0;
}

static void report(const std::vector<int> &codes) {
    for (int c : codes) {
        std::cout << "code=" << c << " error=" << is_error(c) << std::endl;
    }
}

static std::vector<int> parse(const std::vector<std::string> &s) {
    std::vector<int> out;
    out.reserve(s.size());
    for (const auto &x : s) {
        try { out.push_back(std::stoi(x)); }
        catch (...) { out.push_back(-1); }
    }
    return out;
}

} // namespace err_rule_034

int main() {
    using namespace err_rule_034;
    std::vector<std::string> raw = {"0","-1","17","oops"};
    auto codes = parse(raw);
    report(codes);
    return 0;
}
