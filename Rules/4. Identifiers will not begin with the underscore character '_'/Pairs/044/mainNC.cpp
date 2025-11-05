// Context: Packet loss rate calculator — Expanded program

// ------ Non-Compliant Program (044_nc.cpp)
// Context: loss = lost/sent*100
// MISRA: Identifiers must not begin with '_'
// NC: variables begin with '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace _loss_rule_044 {

static float _pct(int _lost, int _sent) { // NC
    if (_sent <= 0) { return 0.0F; }
    return (static_cast<float>(_lost) / static_cast<float>(_sent)) * 100.0F;
}

static void _show(const std::vector<std::pair<int,int>> &_cases) {
    for (const auto &c : _cases) {
        int _sent = c.first;
        int _lost = c.second;
        std::cout << std::fixed << std::setprecision(2)
                  << "loss=" << _pct(_lost, _sent) << "%" << std::endl;
    }
}

} // namespace _loss_rule_044

int main() {
    using namespace _loss_rule_044;
    std::vector<std::pair<int,int>> cases = {{1000,15},{0,1},{500,0}};
    _show(cases);
    return 0;
}
