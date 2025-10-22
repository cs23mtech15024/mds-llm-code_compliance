SEED_PROMPT = """
# MISRA C++ Rule — SEED Meta Prompt (Compact Version)

You are an expert MISRA C++ dataset engineer.
Generate **seed pairs** (non-compliant/compliant) showing a MISRA rule violation and its fix.

---
## RULE CONFIG
```
RULE_NUMBER: {{RULE_NUMBER}}
RULE_DESCRIPTION: {{RULE_DESCRIPTION}}
VIOLATION_TYPE: {{VIOLATION_TYPE}}
FIX_PATTERN: {{FIX_PATTERN}}
RANGE_START: {{RANGE_START}}
RANGE_END: {{RANGE_END}}
```

---
## GOAL
For each seed, output concise C++ code pairs (10–15 lines) that:
- Show one clear violation (`// NC`) and its fix (`// C`).
- Are domain-realistic and compilable with `g++ -std=c++17 -fsyntax-only`.
- Follow consistent structure and naming.

---
## CONTEXT DOMAINS
Use diverse, safety-critical domains like Aerospace, Automotive, Robotics, Industrial, Energy, Medical, Marine, IoT, Rail, and Defense.
Each seed must have a **unique context**.

---
## CONSTRAINTS
1. Seeds numbered sequentially from `{{RANGE_START}}`–`{{RANGE_END}}`.
2. Code must be 10–15 lines, compilable, and domain-appropriate.
3. Only one violation per non-compliant snippet.
4. Compliant version fixes only that violation.
5. Avoid unrelated issues and placeholders.
6. Use standard headers only.
7. Output valid JSONL.

---
## CODE TEMPLATE
```cpp
// Non-Compliant (Seed XXX)
// Context: <domain>
// MISRA C++ {{RULE_NUMBER}} — {{RULE_DESCRIPTION}}
// Violation: {{VIOLATION_TYPE}}
#include <iostream>
namespace app_XXX {
    void func() {
        // violation example // NC
        // realistic logic here
    }
}
int main(){ app_XXX::func(); }
```
Compliant code: identical except fix (`// C`).

---
## SPECIAL RULE NOTES
- **Declarator rules (8-0-1)**: split declarations, avoid range-based loops.
- **Literal suffix rules (2-13-4)**: show lowercase → uppercase literal fixes.

---
## JSONL OUTPUT FORMAT
```json
{"seed":1,"context":"<domain>","noncompliant":"<escaped code>","compliant":"<escaped code>"}
```
Use `\\n` for newlines, `\\` for backslashes, and `\\"` for quotes.

---
## CHECKLIST
- Unique, domain-relevant contexts
- One violation per seed
- Minimal diff between NC/C
- Valid JSONL syntax
- Compiles cleanly

---
## USAGE
1. Fill in rule details.
2. Generate unique seeds using domains above.
3. Validate structure, compilation, and JSON format.
4. Output JSONL lines sequentially for dataset creation.
"""