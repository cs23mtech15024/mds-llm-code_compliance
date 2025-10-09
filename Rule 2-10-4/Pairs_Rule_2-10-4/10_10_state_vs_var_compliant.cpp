// Rule 2-10-4 Compliant: type names are unique; duplicates removed by renaming.
#include <cstdio>
    struct Sink { static void i(int){} static void f(float){} };
    static int entry() { void c(){ enum State{{ Idle, Run }}; }
void d(){{ int state_code=0; Sink::i(state_code); }} return 0; }
    int main() { return entry(); }
