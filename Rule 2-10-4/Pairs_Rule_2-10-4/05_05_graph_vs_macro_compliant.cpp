// Rule 2-10-4 Compliant: type names are unique; duplicates removed by renaming.
#include <cstdio>
    struct Sink { static void i(int){} static void f(float){} };
    static int entry() { #define GRAPH_MAX 256
void use(){ class Graph{{}}; Sink::i(GRAPH_MAX);} return 0; }
    int main() { return entry(); }
