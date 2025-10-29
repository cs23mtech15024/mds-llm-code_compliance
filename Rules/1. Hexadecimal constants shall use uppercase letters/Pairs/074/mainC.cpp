// Context: Firewall packet inspection rule priority

// program_074_c.cpp
// Context: Firewall packet inspection rule priority
// Rule: MISRA C++ 2-13-4 — Hex digits A–F must be uppercase.
// Violation: Uses lowercase hex digits (a-f)

#include <iostream>
#include <cstdint>
#include <vector>
#include <iomanip>

namespace genomics {

struct BaseCall {
    char base;
    uint8_t quality;
    bool is_n_base;
};

class QualityAnalyzer {
private:
    static constexpr uint16_t PHRED_PASS_MASK = 0XAF;     // NC: lowercase a,f
    static constexpr uint16_t N_BASE_MASK = 0X3B;         // NC: lowercase b
    static constexpr uint16_t HIGH_QUALITY = 0XFF;        // NC: lowercase f
    static constexpr uint16_t LOW_QUALITY = 0X0F;         // NC: lowercase f
    static constexpr uint8_t AMBIGUOUS_FLAG = 0XAA;       // NC: lowercase a
    
    std::vector<BaseCall> calls;
    uint32_t statistics;

public:
    QualityAnalyzer() : statistics(0X00000000) {}
    
    void add_base_call(char base, uint8_t quality, bool is_n) {
        calls.push_back({base, quality, is_n});
    }
    
    uint16_t encode_quality_mask(const BaseCall& call) const {
        uint16_t code = 0X0000;
        
        if (call.quality >= 30) {
            code = static_cast<uint16_t>(code | PHRED_PASS_MASK);
        }
        
        if (call.is_n_base) {
            code = static_cast<uint16_t>(code | N_BASE_MASK);
        }
        
        return code;
    }
    
    void compute_statistics() {
        statistics = 0X00;
        uint32_t pass_count = 0;
        
        for (const auto& call : calls) {
            uint16_t mask = encode_quality_mask(call);
            if (mask & PHRED_PASS_MASK) {
                ++pass_count;
            }
        }
        
        statistics = static_cast<uint32_t>((pass_count << 16) | calls.size());
    }
    
    void print_report() const {
        std::cout << "Total calls: " << calls.size() << "\n";
        std::cout << "Statistics: 0x" << std::hex << statistics << std::dec << "\n";
        
        for (size_t i = 0; i < calls.size() && i < 5; ++i) {
            uint16_t mask = encode_quality_mask(calls[i]);
            std::cout << "Call " << i << ": base=" << calls[i].base
                      << " mask=0x" << std::hex << mask << std::dec << "\n";
        }
    }
};

} // namespace genomics

int main() {
    genomics::QualityAnalyzer analyzer;
    
    std::cout << "=== Firewall packet inspection rule priority ===\n";
    
    analyzer.add_base_call('A', 35, false);
    analyzer.add_base_call('C', 28, false);
    analyzer.add_base_call('N', 10, true);
    analyzer.add_base_call('G', 40, false);
    analyzer.add_base_call('T', 32, false);
    
    analyzer.compute_statistics();
    analyzer.print_report();
    
    return 0;
}