// ------ Non-Compliant
// Seed: Non-compliant: int *p, q;   // Compliant: int *p; int q;
// Context: Buffer pointer and size in a DRDO communication handler (simulated).
// Violation: Mixed pointer and non-pointer variables declared on the same line (MISRA C++:2008 Rule 8-0-1).
// Source: MathWorks / Polyspace — MISRA C++:2008 Rule 8-0-1.  [oai_citation:2‡MathWorks](https://es.mathworks.com/help///bugfinder/ref/misrac2008rule801.html?utm_source=chatgpt.com)

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <thread>

// Simulated processing function that takes a pointer and a length
void process_buffer(int *p, int len) {
    // simple deterministic processing: sum and max
    int sum = 0;
    int maxv = (len > 0) ? p[0] : 0;
    for (int i = 0; i < len; ++i) {
        sum += p[i];
        if (p[i] > maxv) maxv = p[i];
    }
    std::cout << "[NC] process_buffer: sum=" << sum << " max=" << maxv << '\n';
}

// Communication handler — NON-COMPLIANT: pointer and plain int declared together
void comm_handler_NC() {
    // seed:
    int *p, q; // NON-COMPLIANT: mixed pointer and non-pointer declarators on one line

    // prepare a small deterministic buffer
    static int buffer[8];
    for (int i = 0; i < 8; ++i) buffer[i] = i + 1;

    // assign pointer and size before use (avoid UB)
    p = buffer;
    q = 8;

    // write a small log
    std::ofstream out("comm_nc.log", std::ios::app);
    if (out) {
        out << "[NC] Starting comm_handler: len=" << q << '\n';
        out.close();
    }

    // process
    process_buffer(p, q);

    // simulate a deterministic delay
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::cout << "[NC] comm_handler completed\n";
}

int main() {
    comm_handler_NC();
    return 0;
}