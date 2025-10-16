// ------ Compliant
// Pair 6 — Seed: 2u -> 2U
// Context: Template-based polynomial evaluation for trajectory calculations.
// Violation: lowercase 'u' suffix.
// Source: MISRA C++ Rule 2-13-4 (literal suffixes shall be upper case).

#include <iostream>
#include <array>

template <typename T, std::size_t N>
class PolynomialEvaluator_C {
public:
    PolynomialEvaluator_C(const std::array<T, N>& coeffs) : coefficients(coeffs) {}

    T evaluate(T x) const {
        T result = 0;
        T power = 1;
        for (std::size_t i = 0; i < N; ++i) {
            result += coefficients[i] * power;
            power *= x;
        }
        return result;
    }

    void demo() const {
        // Seed usage corrected: uppercase 'U'
        unsigned step = 2U; // C
        for (unsigned i = 0; i < 5; i += step) {
            std::cout << "[C] P(" << i << ") = " << evaluate(static_cast<T>(i)) << "\n";
        }
    }

private:
    std::array<T, N> coefficients;
};

int main() {
    std::array<int, 3> coeffs = {1, 2, 3}; // Polynomial: 1 + 2x + 3x^2
    PolynomialEvaluator_C<int, 3> poly(coeffs);
    poly.demo();
    return 0;
}