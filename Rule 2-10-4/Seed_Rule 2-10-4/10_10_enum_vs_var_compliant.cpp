// Rule 2-10-4 Compliant: class/union/enum name is unique across the project; renamed to eliminate duplication.
#include <cstdio>
struct _sink { static void use(int) {} static void usef(float){} };
static int entry() { void a(){ enum Status{ OK=0, FAIL=1 }; } void b(){ int status_val = 0; _sink::use(status_val); } return 0; }
int main() { return entry(); }
