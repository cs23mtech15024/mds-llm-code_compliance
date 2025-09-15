// Compliant: use the static member or remove it if unnecessary.
#include <iostream>
struct Counter {
    static int instances;
    Counter() { ++instances; }
};
int Counter::instances = 0;

int main() {
    Counter a, b;
    std::cout << Counter::instances << '\n';
    return 0;
}
