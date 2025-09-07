// ------ Compliant
// Seed: 1u -> 1U
// Context: Recursive directory search for configuration files in DRDO systems.
// Violation: lowercase 'u' suffix unclear.
// Source: MISRA C++ Rule 2-13-4 (literal suffixes shall be upper case), MathWorks/Polyspace.

#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

class ConfigSearcher_C {
public:
    void searchConfigs(const fs::path& root) {
        if (!fs::exists(root)) {
            std::cerr << "[C] Path not found: " << root << "\n";
            return;
        }

        for (const auto& entry : fs::recursive_directory_iterator(root)) {
            if (entry.is_regular_file() && entry.path().extension() == ".cfg") {
                std::cout << "[C] Found config: " << entry.path() << "\n";
                ++filesFound;
            }
            // Corrected to uppercase suffix
            if (filesFound > 1U) { // C: uppercase 'U'
                std::cout << "[C] Already found multiple configs.\n";
                break;
            }
        }
        std::cout << "[C] Total configs found: " << filesFound << "\n";
    }

private:
    unsigned filesFound = 0U; // C: uppercase 'U'
};

int main() {
    ConfigSearcher_C searcher;
    searcher.searchConfigs("test_configs"); // Provide a directory path
    return 0;
}
