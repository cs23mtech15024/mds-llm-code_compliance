// Compliant: use an unnamed temporary or reference it meaningfully.
#include <iostream>

struct Guard {
    ~Guard() { std::cout << "cleanup\n"; }
};

int main() {
    Guard();                // unnamed temporary - no unused variable
    // or do something with a named guard:
    Guard g2; (void)g2;     // if your project considers this a valid "use"
    return 0;
}
