// ------ Compliant
// Pair 18 — Seed: 256u -> 256U
// Context: Block size for onboard image compression in surveillance UAV system.
// Violation: lowercase 'u' suffix.
// Source: MISRA C++ Rule 2-13-4 (literal suffixes shall be upper case).

#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <iomanip>

// Simple block-based compressor helper (mock) — compliant uses 256U
class ImageCompressor_C {
public:
    // Compliant block size literal (uppercase 'U')
    static constexpr unsigned BLOCK_SIZE = 256U; // C

    // Simulate splitting a grayscale image (1D) into blocks and computing average per block
    std::vector<float> computeBlockAverages(const std::vector<uint8_t>& pixels) const {
        std::vector<float> averages;
        if (pixels.empty()) return averages;
        size_t blocks = (pixels.size() + BLOCK_SIZE - 1U) / BLOCK_SIZE; // C
        averages.reserve(blocks);
        for (size_t b = 0; b < blocks; ++b) {
            size_t start = b * BLOCK_SIZE;
            size_t end = std::min(start + BLOCK_SIZE, pixels.size());
            unsigned sum = 0U; // C
            for (size_t i = start; i < end; ++i) sum += pixels[i];
            averages.push_back(static_cast<float>(sum) / static_cast<float>(end - start));
        }
        return averages;
    }

    void demo() const {
        // create a mock image of 600 pixels (values 0..255)
        std::vector<uint8_t> img(600U);
        for (size_t i = 0U; i < img.size(); ++i) img[i] = static_cast<uint8_t>(i % 256U); // C
        auto avgs = computeBlockAverages(img);
        std::cout << "[C] BLOCK_SIZE = " << BLOCK_SIZE << ", blocks=" << avgs.size() << "\n";
        for (size_t i = 0U; i < avgs.size(); ++i) {
            std::cout << "[C] Block " << i << " avg=" << std::fixed << std::setprecision(2) << avgs[i] << "\n";
        }
    }
};

int main() {
    ImageCompressor_C comp;
    comp.demo();
    return 0;
}