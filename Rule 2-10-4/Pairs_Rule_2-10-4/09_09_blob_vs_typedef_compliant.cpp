// Rule 2-10-4 Compliant: type names are unique; duplicates removed by renaming.
#include <cstdio>
    struct Sink { static void i(int){} static void f(float){} };
    static int entry() { void x(){ union Blob{{ int a; }}; }
void y(){ typedef long Blob_t; Blob_t v=1; Sink::i((int)v);} return 0; }
    int main() { return entry(); }
