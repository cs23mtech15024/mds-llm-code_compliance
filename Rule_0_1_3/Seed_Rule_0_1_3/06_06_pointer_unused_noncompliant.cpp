// Non-compliant: pointer declared and never used.
#include <cstddef>

int main() {
    int* p = NULL; // unused
    return 0;
}
