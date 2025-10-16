// ------ Compliant
// Seed: Non-compliant: double _controlGain = 1.5;   // Compliant: double controlGain = 1.5;
// Context: PID control helper used in a DRDO guidance subsystem.
// Compliance: identifier renamed to avoid leading underscore — complies with MISRA C++:2008 Rule 17-0-1.
// Sources: MathWorks / Polyspace (MISRA 17-0-1).  [oai_citation:11‡MathWorks](https://www.mathworks.com/help/bugfinder/ref/misrac2008rule1701.html?utm_source=chatgpt.com)
//          C++ standard / cppreference (identifier reservation rules).  [oai_citation:12‡Cppreference](https://en.cppreference.com/w/cpp/language/identifiers.html?utm_source=chatgpt.com)
//          clang-tidy bugprone-reserved-identifier (tool guidance).  [oai_citation:13‡Clang](https://clang.llvm.org/extra/clang-tidy/checks/bugprone/reserved-identifier.html?utm_source=chatgpt.com)
//          StackOverflow Q&A: rules about underscores in C/C++ identifiers.  [oai_citation:14‡Stack Overflow](https://stackoverflow.com/questions/228783/what-are-the-rules-about-using-an-underscore-in-a-c-identifier?utm_source=chatgpt.com)
//          Microsoft "Old New Thing" blog (reserved identifier rationale).  [oai_citation:15‡Microsoft for Developers](https://devblogs.microsoft.com/oldnewthing/20230109-00/?p=107685&utm_source=chatgpt.com)

#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <thread>
#include <cmath>

// Compliant PID helper: same logic, identifier without leading underscore
void pid_control_C(const std::vector<double>& refs, const std::vector<double>& measures) {
    static double controlGain = 1.5; // COMPLIANT: no leading underscore
    static double integral = 0.0;
    static double prev_error = 0.0;

    std::ofstream log("pid_c.log", std::ios::app);
    if (!log) {
        std::cerr << "[C] Log open failed\n";
        return;
    }

    const double Kp = controlGain;
    const double Ki = 0.1;
    const double Kd = 0.05;
    const double dt = 0.02; // 20 ms deterministic timestep

    for (size_t i = 0; i < refs.size() && i < measures.size(); ++i) {
        double error = refs[i] - measures[i];
        integral += error * dt;
        double derivative = (error - prev_error) / dt;
        double out = Kp * error + Ki * integral + Kd * derivative;

        prev_error = error;

        log << "[C] t=" << i << " ref=" << refs[i] << " meas=" << measures[i]
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

    pid_control_C(refs, measures);
    std::cout << "[C] PID demo complete\n";
    return 0;
}