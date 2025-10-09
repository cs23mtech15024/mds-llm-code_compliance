// Rule 2-10-4 Non-compliant: duplicate use of a class/union/enum name; must be unique across the project.
#include <cstdio>
    struct Sink { static void i(int){} static void f(float){} };
    static int entry() { void c(){ enum State{{ Idle, Run }}; }
void d(){{ int State=0; Sink::i(State); }} return 0; }
    int main() { return entry(); }
