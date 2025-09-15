// Compliant: either remove or use the static variable.
#include <cstdint>

int get_ticks() {
    static int s_ticks = 0;
    return ++s_ticks;
}

int main() {
    return get_ticks() > 0 ? 0 : 1;
}
