// ------ Compliant
// Pair 12 — Seed: 100u -> 100U
// Context: Unit test threshold for sensor validation using GoogleTest.
// Violation: lowercase 'u' suffix in test value.
// Source: MISRA C++ Rule 2-13-4 (literal suffixes shall be upper case).

#include <iostream>
#include <vector>
#include <cassert>

class SensorValidator_C {
public:
    bool validateReading(unsigned value) const {
        // C: threshold uses uppercase suffix
        return value <= 100U; // C
    }
};

void runUnitTests() {
    SensorValidator_C validator;
    std::vector<unsigned> readings = {50U, 99U, 100U, 101U}; // C
    assert(validator.validateReading(readings[0]) == true);
    assert(validator.validateReading(readings[1]) == true);
    assert(validator.validateReading(readings[2]) == true);
    assert(validator.validateReading(readings[3]) == false);

    std::cout << "[C] All tests passed with threshold 100U\n";
}

int main() {
    runUnitTests();
    return 0;
}