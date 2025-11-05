// Context: Packet loss rate calculator — Expanded program

// ------ Compliant Program (044_c.cpp)
// Context: loss = lost/sent*100
// C: identifiers do not begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace loss_rule_044 {

static float pct(int lost, int sent) {
    if (sent <= 0) { return 0.0F; }
    return (static_cast<float>(lost) / static_cast<float>(sent)) * 100.0F;
}

static void show(const std::vector<std::pair<int,int>> &cases) {
    for (const auto &c : cases) {
        int sent = c.first;
        int lost = c.second;
        std::cout << std::fixed << std::setprecision(2)
                  << "loss=" << pct(lost, sent) << "%" << std::endl;
    }
}

} // namespace loss_rule_044

int main() {
    using namespace loss_rule_044;
    std::vector<std::pair<int,int>> cases = {{1000,15},{0,1},{500,0}};
    show(cases);
    return 0;
}
