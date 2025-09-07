// ------ Compliant
// Pair 7 — Seed: 64UL -> 64ull (in reverse for demonstration)
// Context: Circular buffer for sensor data in DRDO embedded system.
// Violation: lowercase 'ull' suffix.
// Source: MISRA C++ Rule 2-13-4 (literal suffixes shall be upper case).

#include <iostream>
#include <array>
#include <cstdint>

template <typename T, std::size_t N>
class CircularBuffer_C {
public:
    CircularBuffer_C() : head(0), tail(0), count(0) {}

    bool push(const T& value) {
        if (count == N) return false;
        buffer[head] = value;
        head = (head + 1) % N;
        ++count;
        return true;
    }

    bool pop(T& value) {
        if (count == 0) return false;
        value = buffer[tail];
        tail = (tail + 1) % N;
        --count;
        return true;
    }

    void demoFill() {
        // Corrected seed usage: uppercase suffix
        for (std::size_t i = 0; i < 64ULL; ++i) { // C
            push(static_cast<T>(i));
        }
        std::cout << "[C] Filled buffer with " << count << " elements\n";
    }

private:
    std::array<T, N> buffer;
    std::size_t head, tail, count;
};

int main() {
    CircularBuffer_C<int, 128> cb;
    cb.demoFill();
    int val = 0;
    cb.pop(val);
    std::cout << "[C] First popped value = " << val << "\n";
    return 0;
}