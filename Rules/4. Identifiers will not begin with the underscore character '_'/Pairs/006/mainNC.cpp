// Context: Database connection counter — Expanded program

// ------ Non-Compliant Program (006_nc.cpp)
// Context: Connection accounting
// NC: static and members begin with '_'
#include <iostream>
#include <vector>

namespace _db_rule_006 {

class _ConnPool {
public:
    _ConnPool() : _active(0) { }

    void _open() { ++_active; }
    void _close() { if (_active > 0) { --_active; } }
    int _count() const { return _active; }

private:
    int _active;
};

static void _simulate(_ConnPool &_p) {
    _p._open();
    _p._open();
    _p._close();
}

} // namespace _db_rule_006

int main() {
    using namespace _db_rule_006;
    _ConnPool p;
    _simulate(p);
    std::cout << "connections=" << p._count() << std::endl;
    return 0;
}
