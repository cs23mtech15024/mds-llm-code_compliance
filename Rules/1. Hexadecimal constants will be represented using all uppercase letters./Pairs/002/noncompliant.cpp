// ------ Non-Compliant
// Seed: 1u -> 1U
// Context: Recursive directory search for configuration files in DRDO systems.
// Violation: lowercase 'u' suffix unclear.
// Source: MISRA C++ Rule 2-13-4 (literal suffixes shall be upper case), MathWorks/Polyspace.

#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

class ConfigSearcher_NC {
public:
    void searchConfigs(const fs::path& root) {
        if (!fs::exists(root)) {
            std::cerr << "[NC] Path not found: " << root << "\n";
            return;
        }

        for (const auto& entry : fs::recursive_directory_iterator(root)) {
            if (entry.is_regular_file() && entry.path().extension() == ".cfg") {
                std::cout << "[NC] Found config: " << entry.path() << "\n";
                ++filesFound;
            }
            // Example non-compliant suffix usage
            if (filesFound > 1u) { // NC: lowercase 'u'
                std::cout << "[NC] Already found multiple configs.\n";
                break;
            }
        }
        std::cout << "[NC] Total configs found: " << filesFound << "\n";
    }

private:
    unsigned filesFound = 0u; // NC: lowercase 'u'
};

int main() {
    ConfigSearcher_NC searcher;
    searcher.searchConfigs("test_configs"); // Provide a directory path
    return 0;
}
