// Compliant: use the union object.
#include <iostream>
union U {
    int i;
    float f;
};

int main() {
    U u;
    u.i = 7;
    std::cout << u.i << '\n';
    return 0;
}
