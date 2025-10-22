// ------ Compliant (Seed 011)
// Context: Filesystem permission masks (octal) used in POSIX-style code.
// Seed: Non-compliant: const unsigned mode = 0644u;   // Compliant: const unsigned mode = 0644U
// Reference: MISRA C++:2008 Rule 2-13-4 — Literal suffixes shall be upper case (e.g., U, L, UL).

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
    s += (p & 0400U) ? 'r' : '-'; // upper-case 'U' (compliant)
    s += (p & 0200U) ? 'w' : '-';
    s += (p & 0100U) ? 'x' : '-';
    // Group: r (0040), w (0020), x (0010)
    s += (p & 0040U) ? 'r' : '-';
    s += (p & 0020U) ? 'w' : '-';
    s += (p & 0010U) ? 'x' : '-';
    // Other: r (0004), w (0002), x (0001)
    s += (p & 0004U) ? 'r' : '-';
    s += (p & 0002U) ? 'w' : '-';
    s += (p & 0001U) ? 'x' : '-';
    return s;
}

int main() {
    // Typical permission presets (octal). Using upper-case suffixes (compliant).
    const unsigned MODE_FILE  = 0644U;  // rw-r--r--
    const unsigned MODE_EXEC  = 0755U;  // rwxr-xr-x
    const unsigned MODE_SECRET = 0600U; // rw-------

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

    // Combination using upper-case 'UL' (compliant):
    const unsigned special = (04000UL | 02000UL | 01000UL); // setuid, setgid, sticky (illustrative)
    std::cout << "Special bits (oct): " << std::oct << special << "\n";

    return 0;
}