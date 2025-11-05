// Context: Hash bucket index calculator — Expanded program

// ------ Compliant Program (026_c.cpp)
// Context: Key -> bucket mapping
// C: identifiers have no leading '_'
#include <iostream>
#include <vector>
#include <iomanip>

namespace hash_rule_026 {

static int sanitizeSize(int s) {
    if (s <= 0) { return 1; }
    if (s > 1024) { return 1024; }
    return s;
}

static int hash_index(int key, int size) {
    int S = sanitizeSize(size);
    return (key >= 0) ? (key % S) : ((-key) % S);
}

static void batch(const std::vector<int> &keys, int size) {
    for (int k : keys) {
        std::cout << "k=" << k << " idx=" << hash_index(k, size) << std::endl;
    }
}

} // namespace hash_rule_026

int main() {
    using namespace hash_rule_026;
    std::vector<int> keys = {123, -7, 4097};
    batch(keys, 16);
    return 0;
}
