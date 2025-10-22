PROGRAM_PROMPT = """
# MISRA C++ Rule Meta Prompt (Compact Version)

You are an expert C++ programmer and dataset engineer.
Generate **two 40–60 line C++ programs** — one **Non-Compliant** and one **Compliant** — showing a MISRA C++ rule violation and its fix.

---
## RULE CONFIG
```
RULE_NUMBER: {{RULE_NUMBER}}
RULE_DESCRIPTION: {{RULE_DESCRIPTION}}
VIOLATION_TYPE: {{VIOLATION_TYPE}}
FIX_PATTERN: {{FIX_PATTERN}}
```

---
## INPUT (JSONL Seed)
Each seed has fields: `seed`, `context`, `noncompliant`, `compliant` (each 8–15 lines).

---
## TASK
Expand each seed into full 40–60 line programs:
1. **Extract**: use `seed`, `context`, and base code.
2. **Expand**:
   - Add realistic structs/classes, helper functions, loops, and logic.
   - Wrap main logic in a namespace (`app_{{SEED_NUM}}`).
   - Use domain-appropriate naming.
3. **Keep both versions identical** except for rule violation/fix and comment markers (`// NC` vs `// C`).

---
## STRUCTURE

**Non-Compliant ({{SEED_NUM}}_nc.cpp)**
```cpp
// Non-Compliant — MISRA C++ {{RULE_NUMBER}}: {{RULE_DESCRIPTION}}
#include <iostream>\n#include <vector>\n#include <cmath>
namespace app_{{SEED_NUM}} {
    struct {{DomainType}} { /* fields */ }; // NC
    static {{ReturnType}} helper({{params}}) { /* logic */ }
    void mainFunction() {
        // seed + violation here // NC
        // realistic loops + output
    }
}
int main(){ app_{{SEED_NUM}}::mainFunction(); }
```

**Compliant ({{SEED_NUM}}_c.cpp)** — identical except with the fix.

---
## OUTPUT FORMAT
Return JSONL lines:
```json
{"program":{{PROGRAM_NUM}},"context":"{{CONTEXT}}","noncompliant":"{{ESCAPED_NC}}","compliant":"{{ESCAPED_C}}"}
```
Use `\\n` for newlines and escape quotes.

---
## CHECKLIST
- 40–60 lines each
- Compile with `g++ -std=c++17 -Wall -Wextra -pedantic`
- Structurally identical except rule fix
- Domain logic & helper functions
- Correct escaping (`\\n`)

---
## USAGE
Fill in **RULE CONFIG**, provide seed JSONL, and expand both programs accordingly.
"""