// Context: Power grid substation status formatter

// ------ Compliant Program (061_c.cpp)
// Context: Power grid substation status formatter
// MISRA C++ Compliant: Decimal/hex constants only
#include <iostream>
#include <iomanip>
#include <array>
#include <fstream>

namespace oct_061 {
    struct DataPoint {
        int id;
        int value;
        bool processed;
    };
    
    static int processValue(int input, int factor) {
        return input * factor + (input / 2);
    }
    
    static bool validateRange(int val, int min, int max) {
        return (val >= min) && (val <= max);
    }
    
    static void logDataPoint(const DataPoint& dp) {
        std::cout << "[DATA] id=" << dp.id 
                 << " value=" << dp.value
                 << " processed=" << (dp.processed ? "yes" : "no")
                 << std::endl;
    }
    
    void execute() {
        int configValues[] = {8, 16, 64, 128};  // C: decimal constants
        
        std::array<DataPoint, 12> dataset;
        unsigned successCount = 0U;
        unsigned failCount = 0U;
        int totalProcessed = 0;
        
        std::cout << "Starting data processing..." << std::endl;
        std::cout << "Configuration values: 8, 16, 64, 128" << std::endl;
        std::cout << std::endl;
        
        for (size_t i = 0; i < dataset.size(); ++i) {
            int baseValue = configValues[i % 4];
            int processed = processValue(baseValue, 2);
            
            dataset[i].id = static_cast<int>(i);
            dataset[i].value = processed;
            dataset[i].processed = validateRange(processed, 0, 2000);
            
            if (dataset[i].processed) {
                successCount++;
                totalProcessed += processed;
            } else {
                failCount++;
            }
            
            if ((i % 3) == 0) {
                logDataPoint(dataset[i]);
            }
        }
        
        double average = (successCount > 0) ? 
                        (static_cast<double>(totalProcessed) / successCount) : 0.0;
        
        std::cout << "\nProcessing Summary:" << std::endl;
        std::cout << "  Successful:  " << successCount << std::endl;
        std::cout << "  Failed:      " << failCount << std::endl;
        std::cout << "  Total:       " << dataset.size() << std::endl;
        std::cout << "  Average val: " << std::fixed << std::setprecision(2) << average << std::endl;
        
        std::ofstream logFile("processing.log");
        if (logFile.is_open()) {
            logFile << "Processing complete: " << successCount << " success, " 
                   << failCount << " failed" << std::endl;
            logFile.close();
            std::cout << "Log file written successfully" << std::endl;
        }
    }
}

int main() {
    oct_061::execute();
    return 0;
}
