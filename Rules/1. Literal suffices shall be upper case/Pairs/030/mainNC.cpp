// ------ Non-Compliant (Seed 030)
// Context: Embedded Systems — convert ADC digital readings to voltage values.
//          Demonstrates scaling constants and bitmask handling.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violations: lowercase 'f'/'u' suffixes and lowercase hex digits.

#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdint>
#include <cmath>

class ADCReader {
public:
    explicit ADCReader(unsigned resolutionBits)
        : resolutionBits_(resolutionBits), maxValue_((1u << resolutionBits_) - 1u) {} // non-compliant

    float toVoltage(unsigned adcValue) const {
        const float VREF = 3.3f; // non-compliant
        return (adcValue * VREF) / static_cast<float>(maxValue_);
    }

    unsigned maskRaw(unsigned adcValue) const {
        return adcValue & 0x0fffu; // non-compliant
    }

private:
    unsigned resolutionBits_;
    unsigned maxValue_;
};

int main() {
    ADCReader adc(12u); // non-compliant

    std::vector<unsigned> samples = {0u, 512u, 1023u, 2048u, 4095u}; // non-compliant
    std::cout << std::fixed << std::setprecision(3);
    for (unsigned val : samples) {
        std::cout << "ADC " << val
                  << " => Voltage: " << adc.toVoltage(val)
                  << "V | Masked: 0x" << std::hex << adc.maskRaw(val) << std::dec << "\n";
    }
    return 0;
}