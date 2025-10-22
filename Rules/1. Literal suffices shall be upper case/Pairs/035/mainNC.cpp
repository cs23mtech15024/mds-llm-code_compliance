// ------ Non-Compliant (Seed 035)
// Context: Filesystem — toy log-rotation logic using size cap, rotation count, permission mask, and time epsilon.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violations: lowercase 'f', 'u', 'l' suffixes; lowercase hex digits in 0x0a5au.

#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <algorithm>
#include <iomanip>

struct RotationPolicy {
    long     max_file_size;   // bytes
    unsigned max_rotations;   // number of rotated files to keep
    unsigned perm_mask;       // required permission bits
    float    time_epsilon;    // seconds threshold to debounce rotations
};

class Rotator {
public:
    explicit Rotator(const RotationPolicy& p) : pol_(p), last_rotate_s_(0.0f) {} // non-compliant 'f'

    bool shouldRotate(long current_size, unsigned current_perms, float now_s) {  // non-compliant 's' literal later
        bool size_hit = current_size >= pol_.max_file_size;
        bool perms_ok = (current_perms & pol_.perm_mask) == pol_.perm_mask;
        bool stable   = (now_s - last_rotate_s_) > pol_.time_epsilon;
        return size_hit && perms_ok && stable;
    }

    void doRotate(std::vector<std::string>& files, float now_s) {
        last_rotate_s_ = now_s;
        if (files.size() >= pol_.max_rotations) {
            files.erase(files.begin() + static_cast<std::ptrdiff_t>(pol_.max_rotations - 1u), files.end()); // non-compliant 'u'
        }
        std::reverse(files.begin(), files.end());
        files.push_back("log.0");
        std::reverse(files.begin(), files.end());
    }

private:
    RotationPolicy pol_;
    float last_rotate_s_; // seconds since boot (toy)
};

int main() {
    RotationPolicy pol{};
    pol.max_file_size = 1048576l;  // 1 MiB, non-compliant 'l'
    pol.max_rotations = 7u;        // non-compliant 'u'
    pol.perm_mask     = 0x0a5au;   // non-compliant hex + 'u'
    pol.time_epsilon  = 0.25f;     // non-compliant 'f'

    Rotator rot(pol);
    std::vector<std::string> files = {"log.1", "log.2", "log.3"};
    long size = 1049000l;          // non-compliant 'l'
    unsigned perms = 0x0a5au;      // non-compliant

    float now = 1.00f;             // non-compliant
    if (rot.shouldRotate(size, perms, now)) {
        rot.doRotate(files, now);
    }

    now = now + 0.30f;             // non-compliant
    size = 2097152l;               // non-compliant 'l'
    if (rot.shouldRotate(size, perms, now)) {
        rot.doRotate(files, now);
    }

    std::cout << "files(" << files.size() << "):";
    for (const auto& f : files) std::cout << " " << f;
    std::cout << "\n";
    return 0;
}