// ------ Non-Compliant
// Seed: Non-compliant: double _controlGain = 1.5;   // Compliant: double controlGain = 1.5;
// Context: PID control helper used in a DRDO guidance subsystem.
// Violation: identifier begins with '_' — may be reserved (MISRA C++:2008 Rule 17-0-1).
// Sources: MathWorks / Polyspace (MISRA 17-0-1).  [oai_citation:6‡MathWorks](https://www.mathworks.com/help/bugfinder/ref/misrac2008rule1701.html?utm_source=chatgpt.com)
//          C++ standard / cppreference (identifier reservation rules).  [oai_citation:7‡Cppreference](https://en.cppreference.com/w/cpp/language/identifiers.html?utm_source=chatgpt.com)
//          clang-tidy bugprone-reserved-identifier (tool guidance).  [oai_citation:8‡Clang](https://clang.llvm.org/extra/clang-tidy/checks/bugprone/reserved-identifier.html?utm_source=chatgpt.com)
//          StackOverflow Q&A: rules about underscores in C/C++ identifiers.  [oai_citation:9‡Stack Overflow](https://stackoverflow.com/questions/228783/what-are-the-rules-about-using-an-underscore-in-a-c-identifier?utm_source=chatgpt.com)
//          Microsoft "Old New Thing" blog (reserved identifier rationale).  [oai_citation:10‡Microsoft for Developers](https://devblogs.microsoft.com/oldnewthing/20230109-00/?p=107685&utm_source=chatgpt.com)

#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <thread>
#include <cmath>

// Non-compliant PID helper: uses identifier beginning with underscore (seed)
void pid_control_NC(const std::vector<double>& refs, const std::vector<double>& measures) {
    static double _controlGain = 1.5; // NON-COMPLIANT: leading underscore in identifier (seed)
    static double integral = 0.0;
    static double prev_error = 0.0;

    std::ofstream log("pid_nc.log", std::ios::app);
    if (!log) {
        std::cerr << "[NC] Log open failed\n";
        return;
    }

    const double Kp = _controlGain;
    const double Ki = 0.1;
    const double Kd = 0.05;
    const double dt = 0.02; // 20 ms deterministic timestep

    for (size_t i = 0; i < refs.size() && i < measures.size(); ++i) {
        double error = refs[i] - measures[i];
        integral += error * dt;
        double derivative = (error - prev_error) / dt;
        double out = Kp * error + Ki * integral + Kd * derivative;

        prev_error = error;

        log << "[NC] t=" << i << " ref=" << refs[i] << " meas=" << measures[i]
            << " ctrl=" << out << " Kp=" << Kp << '\n';

        // deterministic sleep to simulate real-time control cycle
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }

    log.close();
}

int main() {
    // deterministic test vectors
    std::vector<double> refs(50, 1.0);
    std::vector<double> measures(50);
    for (size_t i = 0; i < measures.size(); ++i) measures[i] = 0.8 + 0.01 * static_cast<double>(i);

    pid_control_NC(refs, measures);
    std::cout << "[NC] PID demo complete\n";
    return 0;
}