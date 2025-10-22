// Context: Smart grid frequency droop compensator

#include <iostream>
int main() {
    const float droop = 3.3f;
    const unsigned nodes = 32u;
    const long key = 101l;
    std::cout << droop * nodes + key << '\n';
    return 0;
}
