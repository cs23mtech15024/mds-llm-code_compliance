// Rule 2-10-4 Compliant: type names are unique; duplicates removed by renaming.
#include <cstdio>
    struct Sink { static void i(int){} static void f(float){} };
    static int entry() { void a(){ union Packet{{ int id; float sz; }}; }
void b(){ int packet_val = 3; Sink::i(packet_val);} return 0; }
    int main() { return entry(); }
