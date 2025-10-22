// Context: Filesystem permission bitmask and checks use 32-bit unsigned hex literals
//          with lowercase 'u' suffix, violating MISRA C++ 2-13-4 (suffixes shall be upper case).
// Seed: Non-compliant: const unsigned int READ = 0x00000001u;  // Compliant: const unsigned int READ = 0X00000001U
// Rule: MISRA C++ 2-13-4 – Literal suffixes shall be upper case.

#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

namespace perms {

// Non-compliant literals (lowercase suffix and hex digits)
constexpr unsigned int READ   = 0x00000001u; // NC
constexpr unsigned int WRITE  = 0x00000002u; // NC
constexpr unsigned int EXEC   = 0x00000004u; // NC
constexpr unsigned int ALL    = READ | WRITE | EXEC;
constexpr unsigned int NONE   = 0x00000000u; // NC
constexpr unsigned int AUDIT  = 0x80000000u; // NC (high bit for auditing)

bool has(unsigned int mask, unsigned int flag) {
    return (mask & flag) == flag;
}

unsigned int grant(unsigned int mask, unsigned int flag) {
    return mask | flag;
}

unsigned int revoke(unsigned int mask, unsigned int flag) {
    return mask & ~flag;
}

std::string to_string(unsigned int mask) {
    std::string s;
    s += has(mask, READ)  ? 'R' : '-';
    s += has(mask, WRITE) ? 'W' : '-';
    s += has(mask, EXEC)  ? 'X' : '-';
    s += has(mask, AUDIT) ? 'A' : '-';
    return s;
}

} // namespace perms

int main() {
    unsigned int user = perms::NONE; // NC
    user = perms::grant(user, perms::READ);
    user = perms::grant(user, perms::WRITE);
    user = perms::grant(user, perms::AUDIT);
    user = perms::revoke(user, perms::WRITE);

    std::cout << "User mask: " << perms::to_string(user) << "\n";
    std::cout << "Has EXEC? " << (perms::has(user, perms::EXEC) ? "yes" : "no") << "\n";
    return 0;
}