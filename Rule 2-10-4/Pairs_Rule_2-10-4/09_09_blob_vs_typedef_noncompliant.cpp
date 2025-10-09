// Rule 2-10-4 Non-compliant: duplicate use of a class/union/enum name; must be unique across the project.
#include <cstdio>
    struct Sink { static void i(int){} static void f(float){} };
    static int entry() { void x(){ union Blob{{ int a; }}; }
void y(){ typedef long Blob; Blob v=1; Sink::i((int)v);} return 0; }
    int main() { return entry(); }
