// Context: Barcode scanner digit buffer

// ------ Compliant Program (018_c.cpp)
// Context: Read first EAN-13 digit, validate ASCII digit
// Rule: COMPLIANT (array by reference retains bound)
#include <iostream>
#include <cstring>
#include <cstddef>

namespace barcode_018_c {

static bool is_digit(char c) { return (c >= '0') && (c <= '9'); }

static void dump_first(const char (&buf)[13]) { // C helper
    std::cout << "first5:";
    for (std::size_t i = 0; i < 5U; ++i) std::cout << ' ' << buf[i];
    std::cout << "\n";
}

void parse_barcode(char (&digits)[13]) { // C API
    dump_first(digits);
    std::cout << "digit0=" << (is_digit(digits[0]) ? digits[0] : '?') << "\n";
}

} // namespace barcode_018_c

int main() {
    using namespace barcode_018_c;
    char barcode[13] = "1234567890128";
    parse_barcode(barcode);
    return 0;
}
