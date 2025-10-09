// Rule 2-10-4 Compliant: class/union/enum name is unique across the project; renamed to eliminate duplication.
#include <cstdio>
struct _sink { static void use(int) {} static void usef(float){} };
static int entry() { void a(){ enum Channel{ A=0,B=1 }; } void b(){ typedef int Channel_t; Channel_t c=1; _sink::use(c); } return 0; }
int main() { return entry(); }
