// Context: Encryption key rotation counter — Expanded program

// ------ Non-Compliant Program (016_nc.cpp)
// Context: Rotation counter
// MISRA: Identifiers must not begin with '_'
// NC: member and methods begin with '_'
#include <iostream>

namespace _rot_rule_016 {

class _Rotator {
public:
    _Rotator() : _rotation_count(0) { }

    void _rotate() { ++_rotation_count; }
    void _rotateMany(int n) { for (int i = 0; i < n; ++i) { _rotate(); } }
    int _count() const { return _rotation_count; }

private:
    int _rotation_count;
};

} // namespace _rot_rule_016

int main() {
    using namespace _rot_rule_016;
    _Rotator r;
    r._rotate();
    r._rotateMany(4);
    std::cout << "rotations=" << r._count() << std::endl;
    return 0;
}
