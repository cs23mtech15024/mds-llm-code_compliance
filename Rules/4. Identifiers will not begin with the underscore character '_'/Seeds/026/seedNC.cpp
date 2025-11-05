// Context: Hash bucket index calculator

// Seed 026 — NC: function starts with underscore
#include <iostream>
int _hash_index(int key, int size) { // NC
    return key % size;
}
int main(){
    std::cout << "idx=" << _hash_index(123, 16) << "\n";
    return 0;
}