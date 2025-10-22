// Context: Smart grid frequency droop compensator

#include <iostream>
int main() {
    const float droop = 3.3F;
    const unsigned nodes = 32U;
    const long key = 101L;
    std::cout << droop * nodes + key << '\n';
    return 0;
}
