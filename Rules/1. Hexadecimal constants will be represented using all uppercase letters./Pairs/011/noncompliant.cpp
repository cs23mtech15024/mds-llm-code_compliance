// ------ Non-Compliant
// Pair 11 — Seed: 5u -> 5U
// Context: FIR filter template for signal conditioning in instrumentation.
// Violation: lowercase 'u' suffix.
// Source: MISRA C++ Rule 2-13-4 (literal suffixes shall be upper case).

#include <array>
#include <iostream>
#include <iomanip>

template <typename T, std::size_t N>
class FIRFilter_NC {
public:
    FIRFilter_NC(const std::array<T, N>& coeffs) : coeffs_(coeffs) {
        buffer_.fill(static_cast<T>(0));
        idx_ = 0u; // NC: lowercase 'u'
    }

    T process(T input) {
        buffer_[idx_] = input;
        T y = 0;
        std::size_t j = idx_;
        for (std::size_t i = 0u; i < N; ++i) {
            y += coeffs_[i] * buffer_[j];
            j = (j + N - 1u) % N; // NC: lowercase 'u'
        }
        idx_ = (idx_ + 1u) % N; // NC: lowercase 'u'
        return y;
    }

    void demo() {
        std::cout << "[NC] FIR filter demo (N=" << N << ")\n";
        for (unsigned i = 0u; i < 8u; ++i) {
            T out = process(static_cast<T>(i * 10));
            std::cout << std::fixed << std::setprecision(2)
                      << "[NC] in=" << i*10 << " out=" << out << "\n";
        }
    }

private:
    std::array<T, N> coeffs_;
    std::array<T, N> buffer_;
    std::size_t idx_;
};

int main() {
    // Seed usage: filter length uses lowercase suffix where applicable
    constexpr std::size_t LEN = 5u; // NC seed: 5u
    std::array<double, LEN> coeffs = {0.1, 0.15, 0.5, 0.15, 0.1};
    FIRFilter_NC<double, LEN> filter(coeffs);
    filter.demo();
    return 0;
}