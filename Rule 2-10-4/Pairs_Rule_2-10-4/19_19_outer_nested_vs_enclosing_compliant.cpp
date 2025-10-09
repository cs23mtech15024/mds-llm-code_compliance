// Rule 2-10-4 Compliant: type names are unique; duplicates removed by renaming.
#include <cstdio>
struct Sink { static void i(int){} static void f(float){} };
static int entry() { struct Hub{{ enum Stage{{ Start, Stop }}; }}; int hub_stage=2; Sink::i(hub_stage); return 0; }
int main() { return entry(); }
