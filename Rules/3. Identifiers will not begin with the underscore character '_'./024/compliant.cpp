// ------ Compliant
// Seed: Non-compliant: #define _DEBUG_LEVEL 2   // Compliant: #define DEBUG_LEVEL 2
// Context: Debug logging configuration used in a DRDO system diagnostics module.
// Compliance: macro identifier renamed to avoid leading underscore — complies with MISRA C++:2008 Rule 17-0-1.
// Sources: MathWorks / Polyspace — MISRA C++:2008 Rule 17-0-1 (reserved identifiers).
//          C++ standard / cppreference — identifier reservation rules (leading underscore / double underscore).
//          clang-tidy bugprone-reserved-identifier — tooling guidance on reserved identifiers.
//          StackOverflow Q&A: rules about using an underscore in a C++ identifier.
//          SEI/CERT DCL51 guidance on reserved identifiers.

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>
#include <vector>

// COMPLIANT: macro without leading underscore
#define DEBUG_LEVEL 2

namespace drdo {
    enum class LogLevel {
        ERROR = 0,
        WARNING = 1,
        INFO = 2,
        DEBUG = 3
    };

    inline std::string levelToString(LogLevel level) {
        switch (level) {
            case LogLevel::ERROR: return "ERROR";
            case LogLevel::WARNING: return "WARNING";
            case LogLevel::INFO: return "INFO";
            case LogLevel::DEBUG: return "DEBUG";
            default: return "UNKNOWN";
        }
    }

    inline void logMessage(LogLevel level, const std::string& message, std::ofstream& log) {
        if (static_cast<int>(level) <= DEBUG_LEVEL) {
            std::string timestamp = "[" + std::to_string(std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::steady_clock::now().time_since_epoch()).count() % 10000) + "ms]";
            
            std::string logEntry = "[C] " + timestamp + " " + levelToString(level) + ": " + message;
            std::cout << logEntry << '\n';
            log << logEntry << '\n';
        }
    }
}

void run_system_diagnostics_C() {
    std::ofstream log("diagnostics_c.log", std::ios::app);
    if (!log) {
        std::cerr << "[C] Failed to open log file\n";
        return;
    }

    drdo::logMessage(drdo::LogLevel::INFO, "System diagnostics started", log);
    
    // Simulate diagnostic checks with different log levels
    std::vector<std::pair<drdo::LogLevel, std::string>> diagnostics = {
        {drdo::LogLevel::INFO, "Initializing hardware interfaces"},
        {drdo::LogLevel::DEBUG, "Memory allocation: 1024KB reserved"},
        {drdo::LogLevel::WARNING, "Sensor calibration drift detected: 0.02%"},
        {drdo::LogLevel::INFO, "Network interface configured"},
        {drdo::LogLevel::DEBUG, "Buffer pool created: 16 buffers"},
        {drdo::LogLevel::ERROR, "Backup sensor offline - using primary only"},
        {drdo::LogLevel::INFO, "Self-test completed"},
        {drdo::LogLevel::DEBUG, "Performance metrics: 99.8% uptime"}
    };

    for (size_t i = 0; i < diagnostics.size(); ++i) {
        drdo::logMessage(diagnostics[i].first, diagnostics[i].second, log);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    drdo::logMessage(drdo::LogLevel::INFO, "System diagnostics completed", log);
    log.close();
}

int main() {
    std::cout << "[C] Debug level configured to: " << DEBUG_LEVEL << '\n';
    run_system_diagnostics_C();
    return 0;
}