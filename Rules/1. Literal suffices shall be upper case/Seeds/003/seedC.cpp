// Context: This example checks if a file size exceeds a floating-point threshold for warning logs.
// Seed: Non-compliant: const float size_limit = 10.5f;   // Compliant: const float size_limit = 10.5F;
// Rule: MISRA C++ 2-13-4 – Literal suffixes shall be upper case.
// Fix: The lowercase suffix ‘f’ is replaced by uppercase ‘F’.

#include <iostream>

int main() {
    const float size_limit = 10.5F; // Compliant literal suffix
    float current = 9.8F;           // Compliant literal suffix

    if (current > size_limit)
        std::cout << "Warning: file exceeds size limit!\n";
    else
        std::cout << "File size acceptable.\n";

    return 0;
}