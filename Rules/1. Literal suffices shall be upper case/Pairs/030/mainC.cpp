// ------ Compliant (Seed 030)
// Context: Embedded Systems — convert ADC digital readings to voltage values.
//          Demonstrates scaling constants and bitmask handling.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Fixes: all suffixes changed to uppercase ('F','U') and hex digits to uppercase.

#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdint>
#include <cmath>

class ADCReader {
public:
    explicit ADCReader(unsigned resolutionBits)
        : resolutionBits_(resolutionBits), maxValue_((1U << resolutionBits_) - 1U) {} // compliant

    float toVoltage(unsigned adcValue) const {
        const float VREF = 3.3F; // compliant
        return (adcValue * VREF) / static_cast<float>(maxValue_);
    }

    unsigned maskRaw(unsigned adcValue) const {
        return adcValue & 0X0FFFU; // compliant
    }

private:
    unsigned resolutionBits_;
    unsigned maxValue_;
};

int main() {
    ADCReader adc(12U); // compliant

    std::vector<unsigned> samples = {0U, 512U, 1023U, 2048U, 4095U}; // compliant
    std::cout << std::fixed << std::setprecision(3);
    for (unsigned val : samples) {
        std::cout << "ADC " << val
                  << " => Voltage: " << adc.toVoltage(val)
                  << "V | Masked: 0x" << std::hex << adc.maskRaw(val) << std::dec << "\n";
    }
    return 0;
}