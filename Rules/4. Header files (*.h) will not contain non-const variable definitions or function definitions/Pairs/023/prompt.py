# prompt_pair23_inline_header.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical embedded code (audience: DRDO).
Do NOT include chain-of-thought. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating:
  MISRA C++:2008 Rule 8-5-2 — "A header file shall contain only declarations and macros."

FOCUS: Show that inline functions are allowed in headers, but non-inline definitions are not.

REQUIRED SEED (include verbatim at the top of both files):
  // Seed: Non-compliant header: void logData() { ... }   // Compliant header: inline void logData() { ... }

PROVENANCE (include in file headers):
  - cppreference: Inline functions (https://en.cppreference.com/w/cpp/language/inline)
  - StackOverflow: "When to use inline functions and where they are allowed?" (common C++ Q/A)
  - MISRA C++:2008 Rule 8-5-2 official rationale (headers must not contain non-inline function definitions)

CONSTRAINTS:
- Produce two self-contained .cpp files (NC and C) as code blocks.
- Must compile cleanly with: g++ -std=c++17 -Wall -Wextra -pedantic
- Target length: ~45–55 lines.
- The only substantive difference between NC and C is whether `logData()` is inline or not.
- Use only standard headers, deterministic output, no UB.
- Context: Logging sensor telemetry.

VALIDATION HINTS:
1. Compile both:
   g++ -std=c++17 -Wall -Wextra -pedantic pair23_nc.cpp -o pair23_nc
   g++ -std=c++17 -Wall -Wextra -pedantic pair23_c.cpp -o pair23_c
2. NC file: header-like region defines a non-inline `void logData()` (violation).
3. C file: header-like region uses `inline void logData()` (compliant).
4. diff -u pair23_nc.cpp pair23_c.cpp should show only the inline keyword and logging prefix differences.

END.
'''