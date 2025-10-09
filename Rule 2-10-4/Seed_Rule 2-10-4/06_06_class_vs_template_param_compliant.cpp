// Rule 2-10-4 Compliant: class/union/enum name is unique across the project; renamed to eliminate duplication.
#include <cstdio>
struct _sink { static void use(int) {} static void usef(float){} };
static int entry() { void a(){ class Node{ }; } template <class NodeT> struct Holder { NodeT n; }; Holder<int> h; (void)h; return 0; }
int main() { return entry(); }
