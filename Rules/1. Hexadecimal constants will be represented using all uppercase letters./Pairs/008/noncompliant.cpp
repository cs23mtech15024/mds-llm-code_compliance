// ------ Non-Compliant
// Pair 8 — Seed: 10u -> 10U
// Context: Logging sensor readings at fixed intervals in a DRDO instrumentation system.
// Violation: lowercase 'u' suffix in timing constant.
// Source: MISRA C++ Rule 2-13-4 (literal suffixes shall be upper case).

#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <thread>
#include <string>

class SensorLogger_NC {
public:
    SensorLogger_NC(const std::string &outFile = "sensor_nc.log")
      : logfile(outFile, std::ios::app), rng(42), dist(0, 100) {
        if (!logfile) {
            std::cerr << "[NC] Failed to open log file\n";
        }
    }

    void runOnce() {
        // Non-compliant timing constant (lowercase 'u')
        constexpr unsigned INTERVAL_MS = 10u; // NC
        int reading = sampleSensor();
        if (logfile) {
            logfile << "[NC] reading: " << reading << "\n";
        } else {
            std::cout << "[NC] reading: " << reading << "\n";
        }
        // Simulate periodic sampling delay
        std::this_thread::sleep_for(std::chrono::milliseconds(INTERVAL_MS));
    }

private:
    int sampleSensor() {
        return dist(rng);
    }

    std::ofstream logfile;
    std::mt19937 rng;
    std::uniform_int_distribution<int> dist;
};

int main() {
    SensorLogger_NC logger("sensor_nc.log");
    // perform a few periodic samples
    for (int i = 0; i < 5; ++i) {
        logger.runOnce();
    }
    return 0;
}