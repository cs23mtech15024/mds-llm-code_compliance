// Rule 2-10-4 Compliant: type names are unique; duplicates removed by renaming.
#include <cstdio>
struct Sink { static void i(int){} static void f(float){} };
static int entry() { namespace N{{ struct Item{{}}; }} using N::Item; void f(){{ int item_count=5; Sink::i(item_count); }} return 0; }
int main() { return entry(); }
