// ------ Non-Compliant
// Seed: Non-compliant: template<typename _DataType>   // Compliant: template<typename DataType>
// Context: Generic data processing template used in a DRDO signal analysis module.
// Violation: template parameter identifier begins with '_' — may be reserved (MISRA C++:2008 Rule 17-0-1).
// Sources: MathWorks / Polyspace — MISRA C++:2008 Rule 17-0-1 (reserved identifiers).
//          C++ standard / cppreference — identifier reservation rules (leading underscore / double underscore).
//          clang-tidy bugprone-reserved-identifier — tooling guidance on reserved identifiers.
//          StackOverflow Q&A: rules about using an underscore in a C++ identifier.
//          SEI/CERT DCL51 guidance on reserved identifiers.

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <numeric>
#include <chrono>
#include <thread>

namespace drdo {
    // NON-COMPLIANT: template parameter with leading underscore (seed)
    template<typename _DataType>
    class SignalProcessor {
    private:
        std::vector<_DataType> buffer;
        size_t windowSize;

    public:
        SignalProcessor(size_t size) : windowSize(size) {
            buffer.reserve(windowSize);
        }

        void addSample(_DataType sample) {
            buffer.push_back(sample);
            if (buffer.size() > windowSize) {
                buffer.erase(buffer.begin());
            }
        }

        _DataType getAverage() const {
            if (buffer.empty()) return static_cast<_DataType>(0);
            _DataType sum = std::accumulate(buffer.begin(), buffer.end(), static_cast<_DataType>(0));
            return sum / static_cast<_DataType>(buffer.size());
        }

        _DataType getPeak() const {
            if (buffer.empty()) return static_cast<_DataType>(0);
            return *std::max_element(buffer.begin(), buffer.end());
        }

        size_t getBufferSize() const { return buffer.size(); }
    };
}

void process_signal_data_NC() {
    drdo::SignalProcessor<double> processor(8);
    std::ofstream log("signal_nc.log", std::ios::app);
    if (!log) {
        std::cerr << "[NC] Log open failed\n";
        return;
    }

    // Simulate processing 20 signal samples
    for (int i = 0; i < 20; ++i) {
        // Deterministic synthetic signal with some variation
        double sample = 100.0 + 20.0 * std::sin(i * 0.3) + (i % 3) * 5.0;
        processor.addSample(sample);
        
        double avg = processor.getAverage();
        double peak = processor.getPeak();
        
        log << "[NC] sample=" << i << " value=" << sample << " avg=" << avg 
            << " peak=" << peak << " buffer_size=" << processor.getBufferSize() << '\n';
            
        std::cout << "[NC] Processed sample " << i << " (avg=" << avg << ")\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(3));
    }

    log.close();
}

int main() {
    process_signal_data_NC();
    std::cout << "[NC] Signal analysis complete\n";
    return 0;
}