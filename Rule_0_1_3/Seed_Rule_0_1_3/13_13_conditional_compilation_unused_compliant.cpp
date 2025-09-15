// Compliant: either use it under the same condition or remove it.
#include <iostream>

int main() {
#ifdef DEBUG_VAR
    int debugLevel = 3;
    std::cout << "debug=" << debugLevel << '\n';
#else
    std::cout << "run\n";
#endif
    return 0;
}
