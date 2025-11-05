// Context: Encryption key rotation counter — Expanded program

// ------ Compliant Program (016_c.cpp)
// Context: Rotation counter
// C: identifiers do not begin with '_'
#include <iostream>

namespace rot_rule_016 {

class Rotator {
public:
    Rotator() : rotation_count_(0) { }

    void rotate() { ++rotation_count_; }
    void rotateMany(int n) { for (int i = 0; i < n; ++i) { rotate(); } }
    int count() const { return rotation_count_; }

private:
    int rotation_count_;
};

} // namespace rot_rule_016

int main() {
    using namespace rot_rule_016;
    Rotator r;
    r.rotate();
    r.rotateMany(4);
    std::cout << "rotations=" << r.count() << std::endl;
    return 0;
}
