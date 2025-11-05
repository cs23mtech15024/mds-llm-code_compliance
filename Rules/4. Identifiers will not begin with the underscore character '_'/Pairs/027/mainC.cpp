// Context: Retry attempt counter — Expanded program

// ------ Compliant Program (027_c.cpp)
// Context: Retry counter increment
// C: identifiers have no leading '_'
#include <iostream>
#include <vector>

namespace ret_rule_027 {

static int add(int a, int b) { return a + b; }

static void bump(int &retry_count) {
    retry_count = add(retry_count, 1);
}

static void run(std::vector<int> &ops) {
    int retry_count = 0;
    for (int op : ops) {
        if ((op % 2) != 0) { bump(retry_count); }
    }
    std::cout << "retries=" << retry_count << std::endl;
}

} // namespace ret_rule_027

int main() {
    using namespace ret_rule_027;
    std::vector<int> ops = {0,1,2,3,4,5};
    run(ops);
    return 0;
}
