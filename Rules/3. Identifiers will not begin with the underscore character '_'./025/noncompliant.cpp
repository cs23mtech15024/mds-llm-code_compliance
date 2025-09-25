// ------ Non-Compliant
// Seed: Non-compliant: int _internalConfig = 0;   // Compliant: int internalConfig = 0;
// Context: Internal configuration variable used within a DRDO cryptographic utilities namespace.
// Violation: namespace-scoped identifier begins with '_' — may be reserved (MISRA C++:2008 Rule 17-0-1).
// Sources: MathWorks / Polyspace — MISRA C++:2008 Rule 17-0-1 (reserved identifiers).
//          C++ standard / cppreference — identifier reservation rules (leading underscore / double underscore).
//          clang-tidy bugprone-reserved-identifier — tooling guidance on reserved identifiers.
//          StackOverflow Q&A: rules about using an underscore in a C++ identifier.
//          SEI/CERT DCL51 guidance on reserved identifiers.

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include <thread>

namespace drdo {
    namespace crypto {
        // NON-COMPLIANT: namespace-scoped identifier with leading underscore (seed)
        int _internalConfig = 0;
        
        enum class CipherMode {
            ENCRYPT = 1,
            DECRYPT = 2
        };

        // Simple deterministic transformation (toy cipher, not cryptographically secure)
        inline std::string simpleTransform(const std::string& input, CipherMode mode) {
            std::string result = input;
            int offset = _internalConfig % 26;
            
            for (char& c : result) {
                if (c >= 'A' && c <= 'Z') {
                    if (mode == CipherMode::ENCRYPT) {
                        c = 'A' + (c - 'A' + offset) % 26;
                    } else {
                        c = 'A' + (c - 'A' - offset + 26) % 26;
                    }
                } else if (c >= 'a' && c <= 'z') {
                    if (mode == CipherMode::ENCRYPT) {
                        c = 'a' + (c - 'a' + offset) % 26;
                    } else {
                        c = 'a' + (c - 'a' - offset + 26) % 26;
                    }
                }
            }
            return result;
        }

        void configureSystem(int keyValue) {
            _internalConfig = (keyValue * 3 + 7) % 100;
        }
    }
}

void run_crypto_operations_NC() {
    std::ofstream log("crypto_nc.log", std::ios::app);
    if (!log) {
        std::cerr << "[NC] Log open failed\n";
        return;
    }

    // Test data
    std::vector<std::string> testMessages = {
        "CONFIDENTIAL", "MISSION", "STATUS", "ABORT", "EXECUTE"
    };

    std::vector<int> configValues = {10, 25, 50, 75, 90};

    for (size_t i = 0; i < testMessages.size(); ++i) {
        // Configure system with different key values
        drdo::crypto::configureSystem(configValues[i % configValues.size()]);
        
        std::string original = testMessages[i];
        std::string encrypted = drdo::crypto::simpleTransform(original, drdo::crypto::CipherMode::ENCRYPT);
        std::string decrypted = drdo::crypto::simpleTransform(encrypted, drdo::crypto::CipherMode::DECRYPT);

        log << "[NC] msg=" << i << " config=" << drdo::crypto::_internalConfig 
            << " orig=" << original << " enc=" << encrypted << " dec=" << decrypted << '\n';
        
        std::cout << "[NC] Message " << i << ": " << original << " -> " << encrypted 
                  << " -> " << decrypted << " (config=" << drdo::crypto::_internalConfig << ")\n";

        std::this_thread::sleep_for(std::chrono::milliseconds(8));
    }

    log.close();
}

int main() {
    std::cout << "[NC] Crypto utilities initialized\n";
    run_crypto_operations_NC();
    std::cout << "[NC] Crypto operations complete\n";
    return 0;
}