"""

You are an expert C++ programmer and dataset curator for safety-critical standards (MISRA C++, AUTOSAR, CERT C++).  
Your task is to generate **one Non-Compliant and one Compliant seed snippet pair** based on information derived from the **PrimeVul dataset** (real-world code violation corpus).

---

## INPUT FORMAT
A JSON entry extracted from PrimeVul, containing:
- `"project"`: repository name  
- `"file_name"`: source file  
- `"violations"`: list of literal or suffix violations (`literal`, `fixed`, `type`)  
- `"cve_desc"`: vulnerability description or context  
- `"commit_url"`: link to fix commit  

---

## OUTPUT REQUIREMENTS

Generate **exactly two C++ seed snippets**:

1️⃣ **Non-Compliant Seed**  
2️⃣ **Compliant Seed**

Each seed must:
- Contain a **single line** showing the literal violation and fix.
- Include a **context comment** summarizing the functionality (derived from `cve_desc` or inferred project intent).  
- Reference the **PrimeVul dataset** as the source.  
- Use **realistic code context** (variable name, type, or constant matching the project domain).  
- Target the correct MISRA rule:  
  **Rule 2-13-4 – Literal suffixes shall be upper case.**

---

## OUTPUT TEMPLATE

### Non-Compliant Seed
```cpp
// Seed: {{SEED_ID}} — Context: {{CONTEXT_SUMMARY}}
// Rule: MISRA C++ 2-13-4 — Literal suffixes shall be upper case
// Source: PrimeVul dataset — {{PROJECT}}, {{FILE_NAME}}
// Violation: uses lowercase suffix in {{LITERAL_TYPE}}
const auto value = {{NON_COMPLIANT_LITERAL}};  // Non-compliant

// Seed: {{SEED_ID}} — Context: {{CONTEXT_SUMMARY}}
// Rule: MISRA C++ 2-13-4 — Literal suffixes shall be upper case
// Source: PrimeVul dataset — {{PROJECT}}, {{FILE_NAME}}
// Correction: suffix changed to uppercase in {{LITERAL_TYPE}}
const auto value = {{COMPLIANT_LITERAL}};  // Compliant

"""