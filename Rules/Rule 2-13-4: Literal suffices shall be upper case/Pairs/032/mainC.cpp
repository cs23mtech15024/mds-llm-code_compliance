// ------ Compliant (Seed 032)
// Context: Cybersecurity — TLS handshake retry logic with exponential backoff.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Fixes: all literal suffixes changed to uppercase ('F','U') and hex digits to uppercase.

#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdint>

struct TlsConfig {
    float base_timeout_s;     // seconds
    unsigned max_retries;
    unsigned cipher_mask;
};

class TlsBackoff {
public:
    explicit TlsBackoff(const TlsConfig& cfg) : cfg_(cfg) {}

    std::vector<float> schedule() const {
        std::vector<float> times;
        float t = cfg_.base_timeout_s;
        for (unsigned i = 0U; i <= cfg_.max_retries; ++i) { // compliant 'U'
            times.push_back(t);
            t *= 2.0F; // compliant 'F'
        }
        return times;
    }

    bool cipherAllowed(uint8_t id) const {
        // Example mask check (not real TLS logic)
        return (static_cast<unsigned>(id) & cfg_.cipher_mask) != 0U; // compliant 'U'
    }

private:
    TlsConfig cfg_;
};

int main() {
    TlsConfig cfg{};
    cfg.base_timeout_s = 0.5F;     // compliant
    cfg.max_retries    = 3U;       // compliant
    cfg.cipher_mask    = 0XFFU;    // compliant hex digits + 'U'

    TlsBackoff backoff(cfg);
    const auto times = backoff.schedule();

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "TLS handshake retry schedule (s):";
    for (float t : times) std::cout << " " << t;
    std::cout << "\n";

    for (uint8_t cid = 0U; cid < 4U; ++cid) { // compliant 'U'
        std::cout << "Cipher " << static_cast<unsigned>(cid)
                  << (backoff.cipherAllowed(cid) ? " allowed" : " blocked") << "\n";
    }
    return 0;
}