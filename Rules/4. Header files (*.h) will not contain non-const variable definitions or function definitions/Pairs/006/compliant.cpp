// ------ Compliant
// Seed: Non-compliant header: int counter = 0;   // Compliant header: extern int counter;
// Context: Header contains only declarations; definitions moved into implementation.
// Source (provenance): StackOverflow Q#1433204 - "How do I use extern to share variables between source files?".  [oai_citation:6‡Stack Overflow](https://stackoverflow.com/questions/1433204/how-do-i-use-extern-to-share-variables-between-source-files?utm_source=chatgpt.com)
//                   : MISRA / static-tool references on header definitions and Rule 8-5-2 (Klocwork / PVS-Studio docs).  [oai_citation:7‡help.klocwork.com](https://help.klocwork.com/current/en-us/concepts/misracpp2008checkerreference_nolinks.htm?utm_source=chatgpt.com)
// Compliance: Header region contains only declarations (extern and prototype); global & function definitions are in the implementation area.

#include <iostream>
#include <string>
#include <thread>
#include <chrono>

// ------------------- good_header.h (inlined here for demo) -------------------
// COMPLIANT: header contains only declarations (no non-const definitions)
//
// Seed (header declaration): extern int counter;
extern int counter; // declaration only

// Function prototype only (no definition in header)
void report_status(const std::string &who);
// ---------------------------------------------------------------------------

// Implementation section: definitions moved out of header area (compliant)
int counter = 0; // COMPLIANT: definition in implementation file

void report_status(const std::string &who) {
    std::cout << "[C] report_status: " << who << " counter=" << counter << '\n';
}

void taskA() {
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
    std::cout << "[C] final counter = " << counter << '\n';
    return 0;
}