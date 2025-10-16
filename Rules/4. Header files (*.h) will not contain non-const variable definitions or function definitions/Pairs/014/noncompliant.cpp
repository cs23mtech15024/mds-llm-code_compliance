// ------ Non-Compliant
// Seed: Non-compliant header: char status_msg[] = "OK";   // Compliant header: extern char status_msg[];
// Context: Header mistakenly defines a non-const C-string and a non-inline function.
// Provenance:
//  - StackOverflow Q#1433204: "How do I use extern to share variables between source files?" (extern guidance).
//  - cppreference: One Definition Rule / Definitions and ODR. https://en.cppreference.com/w/cpp/language/definition
// Violation: Header contains a non-const array definition and a non-inline function definition (violates MISRA C++ Rule 8-5-2).

#include <iostream>
#include <cstring>
#include <thread>
#include <chrono>

// ------------------- bad_header.h (inlined here for demo) -------------------
// NON-COMPLIANT: header contains definitions (violates Rule 8-5-2)
//
// Seed (must appear in header): char status_msg[] = "OK";
char status_msg[] = "OK"; // NON-COMPLIANT: non-const C-string defined in header

// NON-COMPLIANT: non-inline function defined in header
void print_status_and_update(int step) {
    std::cout << "[NC] status=" << status_msg << " step=" << step << '\n';
    // mutate the header-defined array (demonstrates data is modifiable)
    if (step % 2 == 0) {
        std::strncpy(status_msg, "EVEN", sizeof(status_msg));
    } else {
        std::strncpy(status_msg, "ODD", sizeof(status_msg));
    }
}
// ---------------------------------------------------------------------------

int main() {
    for (int i = 0; i < 4; ++i) {
        print_status_and_update(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
    std::cout << "[NC] final status_msg='" << status_msg << "'\n";
    return 0;
}