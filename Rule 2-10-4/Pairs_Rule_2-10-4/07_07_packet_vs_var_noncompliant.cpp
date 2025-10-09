// Rule 2-10-4 Non-compliant: duplicate use of a class/union/enum name; must be unique across the project.
#include <cstdio>
    struct Sink { static void i(int){} static void f(float){} };
    static int entry() { void a(){ union Packet{{ int id; float sz; }}; }
void b(){ int Packet = 3; Sink::i(Packet);} return 0; }
    int main() { return entry(); }
