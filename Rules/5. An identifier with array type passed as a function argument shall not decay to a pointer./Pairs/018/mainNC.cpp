// Context: Barcode scanner digit buffer

// ------ Non-Compliant Program (018_nc.cpp)
// Context: Read first EAN-13 digit, validate ASCII digit
// Rule: Array shall not decay — VIOLATED (digits[] decays)
#include <iostream>
#include <cstring>
#include <cstddef>

namespace barcode_018_nc {

static bool is_digit(char c) { return (c >= '0') && (c <= '9'); }

static void dump_first(const char *buf, std::size_t n) { // NC helper
    std::cout << "first5:";
    for (std::size_t i = 0; i < n && i < 5U; ++i) std::cout << ' ' << buf[i];
    std::cout << "\n";
}

void parse_barcode(char digits[]) { // NC API
    dump_first(digits, 13U);
    char c = digits[0];
    std::cout << "digit0=" << (is_digit(c) ? c : '?') << "\n";
}

} // namespace barcode_018_nc

int main() {
    using namespace barcode_018_nc;
    char barcode[13] = "1234567890128"; // 12 + check
    parse_barcode(barcode);
    return 0;
}
