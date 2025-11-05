// Context: Database connection counter — Expanded program

// ------ Compliant Program (006_c.cpp)
// Context: Connection accounting
// C: identifiers have no leading '_'
#include <iostream>
#include <vector>

namespace db_rule_006 {

class ConnPool {
public:
    ConnPool() : active_(0) { }

    void open() { ++active_; }
    void close() { if (active_ > 0) { --active_; } }
    int count() const { return active_; }

private:
    int active_;
};

static void simulate(ConnPool &p) {
    p.open();
    p.open();
    p.close();
}

} // namespace db_rule_006

int main() {
    using namespace db_rule_006;
    ConnPool p;
    simulate(p);
    std::cout << "connections=" << p.count() << std::endl;
    return 0;
}
