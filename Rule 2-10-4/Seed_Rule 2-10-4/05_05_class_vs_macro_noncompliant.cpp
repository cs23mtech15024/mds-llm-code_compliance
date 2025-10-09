// Rule 2-10-4 Non-compliant: duplicate use of a class/union/enum name; MISRA requires a unique identifier project-wide.
#include <cstdio>
    struct _sink { static void use(int) {} static void usef(float){} };
    static int entry() { #define Matrix 100
void a(){ class Matrix{ public: int n; Matrix():n(0){} }; _sink::use(Matrix); } return 0; }
    int main() { return entry(); }
