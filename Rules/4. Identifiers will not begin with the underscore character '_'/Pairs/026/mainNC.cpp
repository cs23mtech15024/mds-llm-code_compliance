// Context: Hash bucket index calculator — Expanded program

// ------ Non-Compliant Program (026_nc.cpp)
// Context: Key -> bucket mapping
// MISRA: Identifiers must not begin with '_'
// NC: function name begins with '_' 
#include <iostream>
#include <vector>
#include <iomanip>

namespace _hash_rule_026 {

static int _sanitizeSize(int s) {
    if (s <= 0) { return 1; }
    if (s > 1024) { return 1024; }
    return s;
}

static int _hash_index(int key, int size) { // NC
    int S = _sanitizeSize(size);
    return (key >= 0) ? (key % S) : ((-key) % S);
}

static void _batch(const std::vector<int> &_keys, int _size) {
    for (int k : _keys) {
        std::cout << "k=" << k << " idx=" << _hash_index(k, _size) << std::endl;
    }
}

} // namespace _hash_rule_026

int main() {
    using namespace _hash_rule_026;
    std::vector<int> keys = {123, -7, 4097};
    _batch(keys, 16);
    return 0;
}
