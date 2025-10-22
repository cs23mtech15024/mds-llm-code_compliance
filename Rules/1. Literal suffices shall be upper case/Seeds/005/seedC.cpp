// Context: Filesystem permission flags encoded as 32-bit unsigned hex literals.
// Seed: Non-compliant: const unsigned int READ = 0x00000001u;  // Compliant: const unsigned int READ = 0X00000001U
// Rule: MISRA C++ 2-13-4 – Literal suffixes shall be upper case.
// Fix: Suffix changed to 'U' and hex digits capitalized.

#include <cstdint>

int main() {
    const unsigned int READ  = 0X00000001U; // C
    const unsigned int WRITE = 0X00000002U; // C
    const unsigned int EXEC  = 0X00000004U; // C
    (void)READ; (void)WRITE; (void)EXEC;
    return 0;
}