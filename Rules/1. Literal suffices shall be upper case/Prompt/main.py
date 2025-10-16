"""

You are an expert C++ programmer and dataset engineer.  
Your goal is to generate two complete `.cpp` programs — one **Non-Compliant** and one **Compliant** — using a given **seed** (from PrimeVul-derived violations).

---

## INPUT FORMAT

Each input record contains:
- `SEED_ID`: unique seed number
- `RULE_ID`: e.g., 2-13-4
- `RULE_NAME`: e.g., "Literal suffixes shall be upper case"
- `PROJECT`: project name (from PrimeVul)
- `FILE_NAME`: file name
- `CVE_DESC`: short vulnerability context
- `NON_COMPLIANT_LITERAL` / `COMPLIANT_LITERAL`: literal pair
- `CONTEXT_SUMMARY`: one-liner explaining code purpose

---

## OUTPUT REQUIREMENTS
Generate **two compilable C++ programs**:

1️⃣ `// ------ Non-Compliant Program`  
2️⃣ `// ------ Compliant Program`

**Both must:**
- Contain a top comment header with metadata (seed, rule, dataset source, context, violation summary).  
- Be **structurally identical**, except for the literal case difference.  
- Compile under: `g++ -std=c++17 -Wall -Wextra -pedantic`.  
- Use only standard headers.  
- Be ~40–60 lines each.

---

## HEADER COMMENT TEMPLATE
```cpp
// Seed: {{SEED_ID}}
// Rule: MISRA C++ {{RULE_ID}} — {{RULE_NAME}}
// Source: PrimeVul dataset ({{PROJECT}} / {{FILE_NAME}})
// Context: {{CONTEXT_SUMMARY}}
// Violation: {{VIOLATION_DESCRIPTION}}
// Seed: Non-compliant: {{NON_COMPLIANT_LITERAL}}   // Compliant: {{COMPLIANT_LITERAL}}

#include <iostream>
using namespace std;

float computeValue(float base) {
    return base * {{NON_COMPLIANT_LITERAL}}; // Non-compliant literal
}

int main() {
    cout << "Computed value: " << computeValue(0.75F) << endl;
    return 0;
}


#include <iostream>
using namespace std;

float computeValue(float base) {
    return base * {{COMPLIANT_LITERAL}}; // Compliant literal
}

int main() {
    cout << "Computed value: " << computeValue(0.75F) << endl;
    return 0;
}

"""