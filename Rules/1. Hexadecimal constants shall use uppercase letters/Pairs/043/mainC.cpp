// Context: Hover offset literal

// program_043_c.cpp
// Context: Hover offset literal
// Rule: MISRA C++ 2-13-4 — Hex digits A–F must be uppercase.
// Violation: Uses lowercase hex digits (a-f)

#include <iostream>
#include <cstdint>
#include <array>
#include <iomanip>

namespace financial {

class RiskBucketEncoder {
private:
    static constexpr uint8_t CREDIT_RISK_FLAG = 0XA5;    // NC: lowercase a
    static constexpr uint8_t LIQUIDITY_FLAG = 0X1F;      // NC: lowercase f
    static constexpr uint8_t MARKET_RISK_FLAG = 0XBE;    // NC: lowercase b,e
    static constexpr uint8_t OPERATIONAL_FLAG = 0XCD;    // NC: lowercase c,d
    static constexpr uint16_t HIGH_RISK_MASK = 0XFF00;   // NC: lowercase f
    static constexpr uint16_t LOW_RISK_MASK = 0X00FF;    // NC: lowercase f
    
    uint16_t risk_profile;
    uint8_t exposure_level;

public:
    RiskBucketEncoder() : risk_profile(0X0000), exposure_level(0X00) {}
    
    void encode_credit_risk(uint8_t severity) {
        uint8_t encoded = static_cast<uint8_t>(CREDIT_RISK_FLAG ^ severity);
        risk_profile = static_cast<uint16_t>((risk_profile & LOW_RISK_MASK) | (encoded << 8));
    }
    
    void encode_market_risk(uint8_t volatility) {
        uint8_t encoded = static_cast<uint8_t>(MARKET_RISK_FLAG ^ volatility);
        risk_profile = static_cast<uint16_t>((risk_profile & HIGH_RISK_MASK) | encoded);
    }
    
    uint8_t compute_combined_bucket() const {
        uint8_t bucket = CREDIT_RISK_FLAG;
        bucket ^= LIQUIDITY_FLAG;
        bucket ^= MARKET_RISK_FLAG;
        return bucket;
    }
    
    uint16_t get_risk_profile() const { return risk_profile; }
    
    void set_exposure(uint8_t level) {
        exposure_level = static_cast<uint8_t>(level & 0XFF);  // NC: lowercase f
    }
    
    void print_analysis() const {
        std::cout << "Risk Profile: 0x" << std::hex << std::setfill('0')
                  << std::setw(4) << risk_profile << std::dec << "\n";
        std::cout << "Combined Bucket: 0x" << std::hex
                  << static_cast<unsigned>(compute_combined_bucket()) << std::dec << "\n";
        std::cout << "Exposure: 0x" << std::hex
                  << static_cast<unsigned>(exposure_level) << std::dec << "\n";
    }
};

} // namespace financial

int main() {
    financial::RiskBucketEncoder encoder;
    
    // Encode various risk factors with hex values
    encoder.encode_credit_risk(0X0A);      // NC: lowercase a
    encoder.encode_market_risk(0X3F);      // NC: lowercase f
    encoder.set_exposure(0XEF);            // NC: lowercase e,f
    
    std::cout << "=== Hover offset literal ===\n";
    encoder.print_analysis();
    
    // Test combined bucket calculation
    uint8_t combined = encoder.compute_combined_bucket();
    std::cout << "Final bucket code: 0x" << std::hex
              << static_cast<unsigned>(combined) << std::dec << "\n";
    
    return 0;
}