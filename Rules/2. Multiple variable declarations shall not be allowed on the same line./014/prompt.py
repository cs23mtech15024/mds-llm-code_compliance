# prompt_pair14.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 8-0-1:
  "An init-declarator-list or a member-declarator-list shall consist of a single init-declarator or member-declarator respectively."

REQUIRED SEED (include verbatim at top of both files):
  // Seed: Non-compliant: unsigned taskId = 1u, taskPriority = 5u;   // Compliant: unsigned taskId = 1u; unsigned taskPriority = 5u;

CONTEXT:
Task identifier and priority used by an onboard RTOS scheduler in a DRDO system. Provide a realistic ~45–55 line example that registers a small set of tasks, enqueues them, simulates scheduling decisions, logs steps and prints a summary.

VIOLATION (single line):
Declaring multiple variables in one declaration (e.g., `unsigned taskId = 1u, taskPriority = 5u;`) — violates MISRA C++:2008 Rule 8-0-1.

SOURCE:
MathWorks / Polyspace — MISRA C++:2008 Rule 8-0-1 (init-declarator-list must be single). 

REQUIREMENTS:
- Produce two labelled code blocks in this order:
  1) `// ------ Non-Compliant` then the full .cpp file.
  2) `// ------ Compliant` then the full .cpp file.
- Both files must compile with: g++ -std=c++17 -Wall -Wextra -pedantic (use only standard headers).
- Target: ~45–55 lines per file.
- The **only** substantive difference between NC and C must be splitting the multi-declaration into separate declarations. No renames or logic changes.
- Avoid undefined behaviour; keep deterministic and testable.

VALIDATION HINTS:
1. NC file must contain the seed `unsigned taskId = 1u, taskPriority = 5u;`.
2. C file must not contain the seed, and must contain `unsigned taskId = 1u;` and `unsigned taskPriority = 5u;`.
3. Both must compile with the given flags.
4. `diff -u nc.cpp c.cpp` should show only the split declaration.
END.
'''