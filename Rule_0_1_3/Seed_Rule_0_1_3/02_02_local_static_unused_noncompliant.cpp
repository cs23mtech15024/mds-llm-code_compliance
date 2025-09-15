// Non-compliant: function-scope static variable is never referenced.
#include <cstdint>

void tick() {
    static int s_ticks = 0; // unused
}

int main() {
    tick();
    return 0;
}
