// Context: Hash bucket index calculator

// Seed 026 — C: function without underscore prefix
#include <iostream>
int hash_index(int key, int size) { // C
    return key % size;
}
int main(){
    std::cout << "idx=" << hash_index(123, 16) << "\n";
    return 0;
}