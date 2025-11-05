// Context: Stack size allocator — Expanded program

// ------ Compliant Program (098_c.cpp)
// Context: Configure stack size in kilobytes
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace stk_rule_098 {

static int boundKB(int kb) {
    if (kb < 1) { return 1; }
    if (kb > 1048576) { return 1048576; }
    return kb;
}

static void allocate_stack(int size_kb) {
    int s = boundKB(size_kb);
    std::cout << "stack=" << s << "KB" << std::endl;
}

static void demo(const std::vector<int>& vals) {
    for (int v : vals) { allocate_stack(v); }
}

} // namespace stk_rule_098

int main() {
    using namespace stk_rule_098;
    std::vector<int> vals = {64, 0, 2000000};
    demo(vals);
    return 0;
}
