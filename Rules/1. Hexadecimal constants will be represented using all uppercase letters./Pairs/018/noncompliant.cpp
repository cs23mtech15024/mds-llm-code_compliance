// ------ Non-Compliant
// Pair 18 — Seed: 256u -> 256U
// Context: Block size for onboard image compression in surveillance UAV system.
// Violation: lowercase 'u' suffix.
// Source: MISRA C++ Rule 2-13-4 (literal suffixes shall be upper case).

#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <iomanip>

// Simple block-based compressor helper (mock) — non-compliant uses 256u
class ImageCompressor_NC {
public:
    // Non-compliant block size literal (lowercase 'u')
    static constexpr unsigned BLOCK_SIZE = 256u; // NC

    // Simulate splitting a grayscale image (1D) into blocks and computing average per block
    std::vector<float> computeBlockAverages(const std::vector<uint8_t>& pixels) const {
        std::vector<float> averages;
        if (pixels.empty()) return averages;
        size_t blocks = (pixels.size() + BLOCK_SIZE - 1u) / BLOCK_SIZE; // NC
        averages.reserve(blocks);
        for (size_t b = 0; b < blocks; ++b) {
            size_t start = b * BLOCK_SIZE;
            size_t end = std::min(start + BLOCK_SIZE, pixels.size());
            unsigned sum = 0u; // NC
            for (size_t i = start; i < end; ++i) sum += pixels[i];
            averages.push_back(static_cast<float>(sum) / static_cast<float>(end - start));
        }
        return averages;
    }

    void demo() const {
        // create a mock image of 600 pixels (values 0..255)
        std::vector<uint8_t> img(600u);
        for (size_t i = 0u; i < img.size(); ++i) img[i] = static_cast<uint8_t>(i % 256u); // NC
        auto avgs = computeBlockAverages(img);
        std::cout << "[NC] BLOCK_SIZE = " << BLOCK_SIZE << ", blocks=" << avgs.size() << "\n";
        for (size_t i = 0u; i < avgs.size(); ++i) {
            std::cout << "[NC] Block " << i << " avg=" << std::fixed << std::setprecision(2) << avgs[i] << "\n";
        }
    }
};

int main() {
    ImageCompressor_NC comp;
    comp.demo();
    return 0;
}