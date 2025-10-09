// Rule 2-10-4 Compliant: class/union/enum name is unique across the project; renamed to eliminate duplication.
#include <cstdio>
struct _sink { static void use(int) {} static void usef(float){} };
static int entry() { void a(){ enum Mode{ Read=0, Write=1 }; } int Mode_fn(){ return 0; } return Mode_fn(); }
int main() { return entry(); }
