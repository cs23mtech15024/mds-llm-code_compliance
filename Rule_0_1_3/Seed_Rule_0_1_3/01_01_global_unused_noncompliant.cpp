// Non-compliant: Rule 0-1-3 - unused global variable
// A variable defined at namespace scope but never referenced.
#include <cstdint>

int g_counter = 0; // <-- unused

int main() {
    return 0;
}
