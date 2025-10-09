// Rule 2-10-4 Non-compliant: duplicate use of a class/union/enum name; must be unique across the project.
#include <cstdio>
struct Sink { static void i(int){} static void f(float){} };
static int entry() { namespace N{{ struct Item{{}}; }} using N::Item; void f(){{ int Item=5; Sink::i(Item); }} return 0; }
int main() { return entry(); }
