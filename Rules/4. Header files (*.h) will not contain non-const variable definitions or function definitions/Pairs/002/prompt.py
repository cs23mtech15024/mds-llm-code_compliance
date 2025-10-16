# prompt_pair2_header_defs.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 8-5-2:
  "A header file shall contain only declarations and macros."

REQUIRED SEED (include verbatim at the top of both files):
  // Seed: Non-compliant header: bool ready = false;   // Compliant header: extern bool ready;

CONSTRAINTS:
- Produce two self-contained .cpp files (NC and C) as code blocks.
- Both must compile with: g++ -std=c++17 -Wall -Wextra -pedantic
- Target size: ~45–55 lines per file.
- NC must show a header-like region that contains:
    - a non-const variable definition: `bool ready = false;` (seed)
    - a non-inline function *definition* (e.g., `void notify(const char*);` defined in header)
  (these are violations when in headers)
- C must keep the header-like region to *declarations only*:
    - `extern bool ready;`
    - function prototype `void notify(const char*);`
  and must move the variable and function *definitions* into the implementation area.
- The only substantive differences should be the header → implementation relocation (and allowed log prefix changes).

HEADER COMMENTS (both files):
- include the seed line above.
- include a one-line citation to MISRA C++:2008 Rule 8-5-2.
- include a one-line Violation explanation.

VALIDATION:
1. Compile:
   g++ -std=c++17 -Wall -Wextra -pedantic pair2_nc.cpp -o pair2_nc
   g++ -std=c++17 -Wall -Wextra -pedantic pair2_c.cpp -o pair2_c
2. NC must contain the seed `bool ready = false;` in the header-like region.
3. C must contain `extern bool ready;` in the header-like region and the definition `bool ready = false;` only in implementation area.
4. `diff -u pair2_nc.cpp pair2_c.cpp` should show only the header → implementation relocation (plus allowed log prefix differences).

END.
'''