// Rule 2-10-4 Compliant: class/union/enum name is unique across the project; renamed to eliminate duplication.
#include <cstdio>
struct _sink { static void use(int) {} static void usef(float){} };
static int entry() { void a(){ union Cell{ int a; }; } void b(){ typedef int Cell_t; Cell_t z=1; _sink::use(z); } return 0; }
int main() { return entry(); }
