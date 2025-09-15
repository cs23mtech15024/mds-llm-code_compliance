// Non-compliant: variable exists only under a build flag and is unused.
#include <iostream>

int main() {
#ifdef DEBUG_VAR
    int debugLevel = 3; // may be unused across builds
#endif
    std::cout << "run\n";
    return 0;
}
