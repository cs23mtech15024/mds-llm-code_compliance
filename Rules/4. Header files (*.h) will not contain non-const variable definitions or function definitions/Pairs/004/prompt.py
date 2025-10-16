# prompt_pair4_header_defs.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 8-5-2:
  "A header file shall contain only declarations and macros."

REQUIRED SEED (include verbatim at the top of both files):
  // Seed: Non-compliant header: int lookupTable[3] = {1,2,3};   // Compliant header: extern int lookupTable[3];

CONSTRAINTS:
- Produce two self-contained .cpp files (NC and C) as code blocks.
- Both must compile with: g++ -std=c++17 -Wall -Wextra -pedantic
- Target size: ~45–60 lines per file.
- NC file must contain in its header-like region:
    • A non-const global array definition `int lookupTable[3] = {1,2,3};`
    • A non-inline function definition such as `int getValue(int);`
- C file must contain only declarations in the header region:
    • `extern int lookupTable[3];`
    • function prototype only
  and move actual definitions to the implementation section.
- The only substantive difference between NC and C shall be relocating those definitions.

HEADER COMMENTS (both files):
 • include the seed line above.
 • one-line citation to MISRA C++ 2008 Rule 8-5-2.
 • one-line violation / compliance explanation.

VALIDATION HINTS:
1. Compile both:
   g++ -std=c++17 -Wall -Wextra -pedantic pair4_nc.cpp -o pair4_nc
   g++ -std=c++17 -Wall -Wextra -pedantic pair4_c.cpp -o pair4_c
2. NC must contain the seed `int lookupTable[3] = {1,2,3};` in the header-like region.
3. C must contain `extern int lookupTable[3];` there and define the array only in implementation.
4. diff -u pair4_nc.cpp pair4_c.cpp should show only the header→implementation relocation plus allowed log-prefix changes.

END.
'''