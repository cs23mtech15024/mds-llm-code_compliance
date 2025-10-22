// Context: Graphics color constant with lowercase hex prefix/suffix.
// Seed: Non-compliant: const unsigned rgb = 0xff00ffu;   // Compliant: const unsigned rgb = 0XFF00FFU;
// Rule: MISRA C++ 2-13-4 – Literal suffixes shall be upper case (and hex digits typically upper case).

#include <iostream>

int main() {
    const unsigned rgb = 0xff00ffu; // NC: lower '0x' and 'u'
    std::cout << std::hex << rgb << "\n";
    return 0;
}