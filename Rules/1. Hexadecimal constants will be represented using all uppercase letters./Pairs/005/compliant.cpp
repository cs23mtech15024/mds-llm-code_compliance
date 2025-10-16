// ------ Compliant
// Pair 5 — Seed: 100u -> 100U
// Context: Reading buffer size from configuration file for DRDO data stream handling.
// Violation: lowercase 'u' suffix, may be overlooked in code reviews.
// Source: MISRA C++ Rule 2-13-4 (literal suffixes shall be upper case).

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class DataStreamHandler_C {
public:
    DataStreamHandler_C() : buffer(100U, 0) { // C: uppercase 'U'
        std::cout << "[C] Initialized buffer with size 100U\n";
    }

    void loadConfig(const std::string &path) {
        std::ifstream file(path);
        if (!file) {
            std::cerr << "[C] Could not open config file: " << path << "\n";
            return;
        }
        std::string line;
        while (std::getline(file, line)) {
            configLines.push_back(line);
        }
        std::cout << "[C] Loaded " << configLines.size() << " lines from config.\n";
    }

    void process() {
        for (size_t i = 0; i < buffer.size(); ++i) {
            buffer[i] = static_cast<unsigned>(i % 256);
        }
        std::cout << "[C] Processed buffer of size " << buffer.size() << "\n";
    }

private:
    std::vector<unsigned> buffer;
    std::vector<std::string> configLines;
};

int main() {
    DataStreamHandler_C handler;
    handler.loadConfig("config.txt");
    handler.process();
    return 0;
}