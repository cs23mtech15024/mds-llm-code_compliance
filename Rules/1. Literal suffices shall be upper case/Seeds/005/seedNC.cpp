// Context: Filesystem permission flags encoded as 32-bit unsigned hex literals.
// Seed: Non-compliant: const unsigned int READ = 0x00000001u;  // Compliant: const unsigned int READ = 0X00000001U
// Rule: MISRA C++ 2-13-4 – Literal suffixes shall be upper case.
// Violation: Uses lowercase 'u' (and lowercase hex digits).

#include <cstdint>

int main() {
    const unsigned int READ  = 0x00000001u; // NC
    const unsigned int WRITE = 0x00000002u; // NC
    const unsigned int EXEC  = 0x00000004u; // NC
    (void)READ; (void)WRITE; (void)EXEC;
    return 0;
}