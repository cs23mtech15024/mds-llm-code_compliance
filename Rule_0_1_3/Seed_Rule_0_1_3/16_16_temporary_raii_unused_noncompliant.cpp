// Non-compliant: guard variable is declared solely for RAII; never referenced.
#include <iostream>

struct Guard {
    ~Guard() { std::cout << "cleanup\n"; }
};

int main() {
    Guard g; // unused variable (even though destructor runs)
    return 0;
}
