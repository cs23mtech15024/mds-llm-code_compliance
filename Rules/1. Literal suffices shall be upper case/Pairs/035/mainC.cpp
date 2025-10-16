// ------ Compliant (Seed 035)
// Context: Filesystem — toy log-rotation logic using size cap, rotation count, permission mask, and time epsilon.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Fixes: all literal suffixes uppercase ('F','U','L') and hex digits to uppercase (0X0A5AU).

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
    explicit Rotator(const RotationPolicy& p) : pol_(p), last_rotate_s_(0.0F) {}

    bool shouldRotate(long current_size, unsigned current_perms, float now_s) {
        bool size_hit = current_size >= pol_.max_file_size;
        bool perms_ok = (current_perms & pol_.perm_mask) == pol_.perm_mask;
        bool stable   = (now_s - last_rotate_s_) > pol_.time_epsilon;
        return size_hit && perms_ok && stable;
    }

    void doRotate(std::vector<std::string>& files, float now_s) {
        last_rotate_s_ = now_s;
        if (files.size() >= pol_.max_rotations) {
            files.erase(files.begin() + static_cast<std::ptrdiff_t>(pol_.max_rotations - 1U), files.end());
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
    pol.max_file_size = 1048576L;  // 1 MiB, compliant
    pol.max_rotations = 7U;        // compliant
    pol.perm_mask     = 0X0A5AU;   // compliant hex + 'U'
    pol.time_epsilon  = 0.25F;     // compliant

    Rotator rot(pol);
    std::vector<std::string> files = {"log.1", "log.2", "log.3"};
    long size = 1049000L;          // compliant
    unsigned perms = 0X0A5AU;      // compliant

    float now = 1.00F;             // compliant
    if (rot.shouldRotate(size, perms, now)) {
        rot.doRotate(files, now);
    }

    now = now + 0.30F;             // compliant
    size = 2097152L;               // compliant
    if (rot.shouldRotate(size, perms, now)) {
        rot.doRotate(files, now);
    }

    std::cout << "files(" << files.size() << "):";
    for (const auto& f : files) std::cout << " " << f;
    std::cout << "\n";
    return 0;
}