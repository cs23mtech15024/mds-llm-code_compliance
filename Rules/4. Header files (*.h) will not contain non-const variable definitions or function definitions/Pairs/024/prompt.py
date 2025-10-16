# prompt_pair24_constexpr_header.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical embedded code (audience: DRDO).
Do NOT include chain-of-thought. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating:
  MISRA C++:2008 Rule 8-5-2 — "A header file shall contain only declarations and macros."

FOCUS: Show that constexpr variable definitions are allowed in headers, whereas non-constexpr definitions are not.

REQUIRED SEED (include verbatim at the top of both files):
  // Seed: Non-compliant header: int buffer_size = 128;   // Compliant header: constexpr int buffer_size = 128;

PROVENANCE (include in file headers):
  - cppreference: constexpr variables (https://en.cppreference.com/w/cpp/language/constexpr)
  - StackOverflow: “Difference between const and constexpr in headers” (common C++ question)
  - MISRA C++:2008 Rule 8-5-2 rationale (internal linkage exceptions)

CONSTRAINTS:
- Produce two self-contained .cpp files (NC and C) as code blocks.
- Must compile cleanly with: g++ -std=c++17 -Wall -Wextra -pedantic
- Target size: ~45–55 lines.
- The only substantive difference between NC and C is that NC uses a plain global definition (`int buffer_size = 128;`)
  while C uses `constexpr int buffer_size = 128;`.
- Use only standard headers, deterministic output, no UB.
- Context: buffer allocation for telemetry packet.

VALIDATION HINTS:
1. Compile both:
   g++ -std=c++17 -Wall -Wextra -pedantic pair24_nc.cpp -o pair24_nc
   g++ -std=c++17 -Wall -Wextra -pedantic pair24_c.cpp -o pair24_c
2. NC file must define `int buffer_size = 128;` in the header-like region (violation).
3. C file must define `constexpr int buffer_size = 128;` (compliant).
4. diff -u pair24_nc.cpp pair24_c.cpp should show only the constexpr keyword difference (and log prefixes).

END.
'''