# prompt_pair25_multiple_violations.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 8-5-2:
  "A header file shall contain only declarations and macros."

FOCUS:
Demonstrate multiple violations in a single header-like region:
 - Two non-const global variable definitions
 - Two non-inline function definitions
The compliant variant must move both variables and both functions into the implementation area, leaving only `extern` declarations and prototypes in the header-like region.

REQUIRED SEED (include verbatim at the top of both files):
  // Seed: Non-compliant header: int g_counter = 0; double calibration = 1.5;  // Compliant header: extern int g_counter; extern double calibration;

PROVENANCE (include in file headers):
  - StackOverflow Q#1433204: guidance on extern vs defining globals in headers (https://stackoverflow.com/questions/1433204/how-do-i-use-extern-to-share-variables-between-source-files).
  - cppreference: One Definition Rule / Definitions and ODR (https://en.cppreference.com/w/cpp/language/definition).
  - PVS-Studio / static-analyzer guidance on avoiding variable definitions in headers (MISRA-related).

CONSTRAINTS:
- Produce two self-contained .cpp files (NC and C) as code blocks.
- Both must compile with: g++ -std=c++17 -Wall -Wextra -pedantic
- Target size: ~45–60 lines per file.
- NC must include the header-like region that contains the seed (two global definitions) and two non-inline function definitions in the header (multiple violations).
- C must change the header-like region to only contain `extern` declarations and function prototypes and move the two variable definitions and two function definitions into the implementation area.
- The ONLY substantive textual differences between NC and C should be relocation of the global and function definitions to implementation and minor NC/C log prefixes.
- Deterministic behavior; avoid UB and leaks; use only standard headers.

VALIDATION HINTS:
1. Compile both:
   g++ -std=c++17 -Wall -Wextra -pedantic pair25_nc.cpp -o pair25_nc
   g++ -std=c++17 -Wall -Wextra -pedantic pair25_c.cpp -o pair25_c
2. NC must contain the seed `int g_counter = 0; double calibration = 1.5;` in the header-like region.
3. C must contain `extern int g_counter; extern double calibration;` in the header-like region and define the globals only in implementation.
4. diff -u pair25_nc.cpp pair25_c.cpp should show only header→implementation relocation and allowed log-prefix differences.

END.
'''