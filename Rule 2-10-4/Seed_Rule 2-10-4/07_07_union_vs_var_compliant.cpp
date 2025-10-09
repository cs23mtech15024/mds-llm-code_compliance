// Rule 2-10-4 Compliant: class/union/enum name is unique across the project; renamed to eliminate duplication.
#include <cstdio>
struct _sink { static void use(int) {} static void usef(float){} };
static int entry() { void f(){ union Payload{ int a; float b; }; } void g(){ int payload_value = 7; _sink::use(payload_value); } return 0; }
int main() { return entry(); }
