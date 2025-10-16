// ------ Non-Compliant
// Pair 12 — Seed: 100u -> 100U
// Context: Unit test threshold for sensor validation using GoogleTest.
// Violation: lowercase 'u' suffix in test value.
// Source: MISRA C++ Rule 2-13-4 (literal suffixes shall be upper case).

#include <iostream>
#include <vector>
#include <cassert>

class SensorValidator_NC {
public:
    bool validateReading(unsigned value) const {
        // NC: threshold uses lowercase suffix
        return value <= 100u; // NC
    }
};

void runUnitTests() {
    SensorValidator_NC validator;
    std::vector<unsigned> readings = {50u, 99u, 100u, 101u}; // NC
    assert(validator.validateReading(readings[0]) == true);
    assert(validator.validateReading(readings[1]) == true);
    assert(validator.validateReading(readings[2]) == true);
    assert(validator.validateReading(readings[3]) == false);

    std::cout << "[NC] All tests passed with threshold 100u\n";
}

int main() {
    runUnitTests();
    return 0;
}