// ------ Non-Compliant (Seed 011)
// Context: Filesystem permission masks (octal) used in POSIX-style code.
// Seed: Non-compliant: const unsigned mode = 0644u;   // Compliant: const unsigned mode = 0644U
// Reference: MISRA C++:2008 Rule 2-13-4 — Literal suffixes shall be upper case (e.g., U, L, UL).
// Violation: Uses lower-case integer suffixes ('u', 'ul') on integer literals.

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

struct Entry {
    std::string name;
    unsigned permissions; // POSIX-style permission mask (octal)
};

static std::string perm_to_string(unsigned p) {
    auto bit = [&](unsigned m) { return (p & m) ? 'r' : '-'; };
    // Only for illustration; not a full POSIX decoder.
    std::string s;
    // Owner: r (0400), w (0200), x (0100)
    s += (p & 0400u) ? 'r' : '-'; // lower-case 'u' (non-compliant)
    s += (p & 0200u) ? 'w' : '-';
    s += (p & 0100u) ? 'x' : '-';
    // Group: r (0040), w (0020), x (0010)
    s += (p & 0040u) ? 'r' : '-';
    s += (p & 0020u) ? 'w' : '-';
    s += (p & 0010u) ? 'x' : '-';
    // Other: r (0004), w (0002), x (0001)
    s += (p & 0004u) ? 'r' : '-';
    s += (p & 0002u) ? 'w' : '-';
    s += (p & 0001u) ? 'x' : '-';
    return s;
}

int main() {
    // Typical permission presets (octal). Intentionally using lower-case suffixes for violation.
    const unsigned MODE_FILE  = 0644u;  // rw-r--r--
    const unsigned MODE_EXEC  = 0755u;  // rwxr-xr-x
    const unsigned MODE_SECRET = 0600u; // rw-------

    std::vector<Entry> entries = {
        {"README.md", MODE_FILE},
        {"run.sh",    MODE_EXEC},
        {"secret.key", MODE_SECRET}
    };

    std::cout << "Listing with octal perms:\n";
    for (const auto& e : entries) {
        std::cout << std::left << std::setw(12) << e.name
                  << " perms(oct): " << std::oct << e.permissions
                  << "  perms(txt): " << perm_to_string(e.permissions) << "\n";
    }

    // Demonstrate a combination using lower-case 'ul' (still non-compliant):
    const unsigned special = (04000ul | 02000ul | 01000ul); // setuid, setgid, sticky (illustrative)
    std::cout << "Special bits (oct): " << std::oct << special << "\n";

    return 0;
}