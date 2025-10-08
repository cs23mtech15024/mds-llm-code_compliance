// ------ Non-Compliant
// Seed: Non-compliant header: int counter = 0;   // Compliant header: extern int counter;
// Context: Adapted example showing a header that incorrectly defines a non-const global and a non-inline function.
// Source (provenance): StackOverflow Q#1433204 - "How do I use extern to share variables between source files?".  [oai_citation:4‡Stack Overflow](https://stackoverflow.com/questions/1433204/how-do-i-use-extern-to-share-variables-between-source-files?utm_source=chatgpt.com)
//                   : MISRA / static-tool references on header definitions and Rule 8-5-2 (Klocwork / PVS-Studio docs).  [oai_citation:5‡help.klocwork.com](https://help.klocwork.com/current/en-us/concepts/misracpp2008checkerreference_nolinks.htm?utm_source=chatgpt.com)
// Violation: Header contains a non-const variable definition and a non-inline function definition (violates MISRA C++ Rule 8-5-2).

#include <iostream>
#include <string>
#include <thread>
#include <chrono>

// ------------------- bad_header.h (inlined here for demo) -------------------
// NON-COMPLIANT: header contains definitions (violation of MISRA Rule 8-5-2)
//
// Seed (must appear in header): int counter = 0;
int counter = 0; // NON-COMPLIANT: non-const global definition in header

// NON-COMPLIANT: non-inline function definition inside header
void report_status(const std::string &who) {
    std::cout << "[NC] report_status: " << who << " counter=" << counter << '\n';
}
// ---------------------------------------------------------------------------

void taskA() {
    // increments shared counter and reports
    ++counter;
    report_status("taskA");
    std::this_thread::sleep_for(std::chrono::milliseconds(3));
}

void taskB() {
    ++counter;
    report_status("taskB");
    std::this_thread::sleep_for(std::chrono::milliseconds(3));
}

int main() {
    taskA();
    taskB();
    std::cout << "[NC] final counter = " << counter << '\n';
    return 0;
}