// Rule 2-10-4 Compliant: class/union/enum name is unique across the project; renamed to eliminate duplication.
#include <cstdio>
struct _sink { static void use(int) {} static void usef(float){} };
static int entry() { namespace A{ struct Tag{}; } using A::Tag; void f(){ int tag_val = 1; _sink::use(tag_val); } return 0; }
int main() { return entry(); }
