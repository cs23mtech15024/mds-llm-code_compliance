# prompt_pair22_static_member_header.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 8-5-2:
  "A header file shall contain only declarations and macros."

REQUIRED SEED (include verbatim at the top of both files):
  // Seed: Non-compliant header: int S::x = 5;   // Compliant: move definition to implementation

PROVENANCE (include in file headers):
  - cppreference: static data member definitions (https://en.cppreference.com/w/cpp/language/static).
  - StackOverflow: "Defining static class member in header causes multiple definitions" (common Q/A).

CONSTRAINTS:
- Produce two self-contained .cpp files (NC and C) as code blocks.
- Both must compile with: g++ -std=c++17 -Wall -Wextra -pedantic
- Target size: ~45–55 lines per file.
- NC must include a header-like region that:
    • Declares `struct S { static int x; };`
    • Defines `int S::x = 5;` in the header-like region (seed).
    • Optionally contains a non-inline function definition in header-like region (to illustrate function-definition violation).
- C must change the header-like region to keep only declarations (`struct S { static int x; };` and prototype) and move `int S::x = 5;` and function definition to the implementation area.
- The ONLY substantive textual difference between NC and C should be relocating the static member definition and any function definitions out of the header-like region into the implementation region (and allowed NC/C log-prefix differences).
- Avoid undefined behaviour; keep logic deterministic and testable.

VALIDATION HINTS:
1. Compile both:
   g++ -std=c++17 -Wall -Wextra -pedantic pair22_nc.cpp -o pair22_nc
   g++ -std=c++17 -Wall -Wextra -pedantic pair22_c.cpp -o pair22_c
2. NC must contain the seed `int S::x = 5;` in the header-like region.
3. C must not contain `int S::x = 5;` in the header-like region — it must appear only in the implementation section.
4. diff -u pair22_nc.cpp pair22_c.cpp should show only the relocation of the `S::x` definition and the function body from header to implementation (plus allowed log-prefix differences).

END.
'''