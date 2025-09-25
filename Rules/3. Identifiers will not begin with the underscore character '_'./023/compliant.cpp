// ------ Compliant
// Seed: Non-compliant: void process(int _inputData)   // Compliant: void process(int inputData)
// Context: Data validation function used in a DRDO communication protocol handler.
// Compliance: function parameter identifier renamed to avoid leading underscore — complies with MISRA C++:2008 Rule 17-0-1.
// Sources: MathWorks / Polyspace — MISRA C++:2008 Rule 17-0-1 (reserved identifiers).
//          C++ standard / cppreference — identifier reservation rules (leading underscore / double underscore).
//          clang-tidy bugprone-reserved-identifier — tooling guidance on reserved identifiers.
//          StackOverflow Q&A: rules about using an underscore in a C++ identifier.
//          SEI/CERT DCL51 guidance on reserved identifiers.

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>

namespace drdo {
    enum class ValidationResult {
        VALID,
        INVALID_RANGE,
        INVALID_CHECKSUM,
        INVALID_FORMAT
    };

    inline std::string resultToString(ValidationResult result) {
        switch (result) {
            case ValidationResult::VALID: return "VALID";
            case ValidationResult::INVALID_RANGE: return "INVALID_RANGE";
            case ValidationResult::INVALID_CHECKSUM: return "INVALID_CHECKSUM";
            case ValidationResult::INVALID_FORMAT: return "INVALID_FORMAT";
            default: return "UNKNOWN";
        }
    }
}

// COMPLIANT: function parameter without leading underscore
drdo::ValidationResult validateCommData(int inputData, std::ofstream& log) {
    // Range validation
    if (inputData < 0 || inputData > 9999) {
        log << "[C] inputData=" << inputData << " result=INVALID_RANGE\n";
        return drdo::ValidationResult::INVALID_RANGE;
    }

    // Simple checksum validation (deterministic)
    int checksum = 0;
    int temp = inputData;
    while (temp > 0) {
        checksum += temp % 10;
        temp /= 10;
    }

    if (checksum % 7 != 0) {
        log << "[C] inputData=" << inputData << " checksum=" << checksum << " result=INVALID_CHECKSUM\n";
        return drdo::ValidationResult::INVALID_CHECKSUM;
    }

    // Format validation (must be 4 digits when non-zero)
    if (inputData != 0 && inputData < 1000) {
        log << "[C] inputData=" << inputData << " result=INVALID_FORMAT\n";
        return drdo::ValidationResult::INVALID_FORMAT;
    }

    log << "[C] inputData=" << inputData << " result=VALID\n";
    return drdo::ValidationResult::VALID;
}

void run_protocol_validation_C() {
    std::ofstream log("protocol_c.log", std::ios::app);
    if (!log) {
        std::cerr << "[C] Log open failed\n";
        return;
    }

    // Deterministic test data
    std::vector<int> testData = {1234, 5678, 2107, 9999, -100, 500, 7000, 0, 1001, 8400};

    int validCount = 0;
    for (size_t i = 0; i < testData.size(); ++i) {
        drdo::ValidationResult result = validateCommData(testData[i], log);
        std::cout << "[C] Data " << i << ": " << testData[i] 
                  << " -> " << drdo::resultToString(result) << "\n";

        if (result == drdo::ValidationResult::VALID) {
            validCount++;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }

    log << "[C] Validation complete: " << validCount << "/" << testData.size() << " valid\n";
    log.close();
    std::cout << "[C] Protocol validation complete: " << validCount << " valid packets\n";
}

int main() {
    run_protocol_validation_C();
    return 0;
}