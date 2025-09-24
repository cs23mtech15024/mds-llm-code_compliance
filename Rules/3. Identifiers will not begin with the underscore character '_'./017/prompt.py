# prompt_pair17_ident_underscore_devicecount.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 17-0-1:
  "Reserved identifiers, macros and functions in the Standard Library shall not be defined, redefined or undefined."

REQUIRED SEED (include verbatim at top of both files):
  // Seed: Non-compliant: size_t _deviceCount = 0;   // Compliant: size_t deviceCount = 0;

CONTEXT:
Device management helper in a DRDO embedded monitoring system. Produce two self-contained .cpp files (NC and C), ~45-55 lines each, compilable with:
  g++ -std=c++17 -Wall -Wextra -pedantic

CONSTRAINT:
The ONLY substantive textual difference between NC and C files must be the identifier `_deviceCount` → `deviceCount`. Do not rename other identifiers, change control flow, or alter formatting except NC/C markers and log prefixes.

VIOLATION (one line):
Using an identifier beginning with '_' (leading underscore) may be reserved by the implementation — this violates MISRA C++:2008 Rule 17-0-1 (reserved identifiers).  

SOURCES (include in file headers):
- MathWorks / Polyspace — MISRA C++:2008 Rule 17-0-1.  [oai_citation:2‡MathWorks](https://kr.mathworks.com/help/bugfinder/ref/misrac2008rule1701.html?utm_source=chatgpt.com)  
- PVS-Studio: “Identifiers that start with `__` or `_[A-Z]` are reserved.”  [oai_citation:3‡PVS-Studio](https://pvs-studio.com/en/pvs-studio/sast/misra/?utm_source=chatgpt.com)  
- C++ standard / cppreference — rules on reserved identifiers (leading underscore).  [oai_citation:4‡SciTools Documentation](https://docs.scitools.com/codecheck/path_7.html?utm_source=chatgpt.com)  
- StackOverflow Q&A about identifiers starting with underscore.  [oai_citation:5‡Stack Overflow](https://stackoverflow.com/questions/6397780/names-starting-with-underscore-shows-errors-page-doesnot-exists-for-gh-pages-bra?utm_source=chatgpt.com)  

VALIDATION HINTS (exact):
1. Compile both files:
   g++ -std=c++17 -Wall -Wextra -pedantic nc.cpp -o nc_test  
   g++ -std=c++17 -Wall -Wextra -pedantic c.cpp -o c_test  
2. NC must contain `_deviceCount`:
   grep -E '\b_deviceCount\b' nc.cpp  
3. C must contain `deviceCount` and must NOT contain `_deviceCount`:
   grep -E '\bdeviceCount\b' c.cpp  
   ! grep -E '\b_deviceCount\b' c.cpp  
4. `diff -u nc.cpp c.cpp` should show only `_deviceCount` → `deviceCount`.

END.
'''