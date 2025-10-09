// Rule 2-10-4 Compliant: class/union/enum name is unique across the project; renamed to eliminate duplication.
#include <cstdio>
struct _sink { static void use(int) {} static void usef(float){} };
static int entry() { void f(){ class Grid{ }; _sink::use(0);} void g(){ class Grid2{ }; _sink::use(1);} return 0; }
int main() { return entry(); }
