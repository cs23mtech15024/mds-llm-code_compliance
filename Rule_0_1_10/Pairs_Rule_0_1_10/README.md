# Pairs_Rule_0_1_10 — Mapping & Rationale

This folder contains **20 paired examples** (non-compliant/compliant) for *MISRA C++:2008 Rule 0-1-10* — “Every defined function shall be called at least once.”

For each pattern, we list the seed file, and the two generated files.


---

## 01. Free function defined but never called
- **Seed:** `01_free_function_never_called.cpp`
- **Non-compliant:** `01_free_function_never_called_noncompliant.cpp`
- **Compliant:** `01_free_function_never_called_compliant.cpp`
- **Rationale:** Rule 0-1-10 requires every defined function to be called; the compliant version ensures at least one actual call (or removes the unused definition).

## 02. File-scope static function never called
- **Seed:** `01_placeholder_never_called.cpp`
- **Non-compliant:** `02_static_filescope_never_called_noncompliant.cpp`
- **Compliant:** `02_static_filescope_never_called_compliant.cpp`
- **Rationale:** Rule 0-1-10 requires every defined function to be called; the compliant version ensures at least one actual call (or removes the unused definition).

## 03. Non-static member function never called
- **Seed:** `02_placeholder_never_called.cpp`
- **Non-compliant:** `03_member_function_never_called_noncompliant.cpp`
- **Compliant:** `03_member_function_never_called_compliant.cpp`
- **Rationale:** Rule 0-1-10 requires every defined function to be called; the compliant version ensures at least one actual call (or removes the unused definition).

## 04. Virtual override defined but never called
- **Seed:** `02_static_filescope_never_called.cpp`
- **Non-compliant:** `04_virtual_override_never_called_noncompliant.cpp`
- **Compliant:** `04_virtual_override_never_called_compliant.cpp`
- **Rationale:** Rule 0-1-10 requires every defined function to be called; the compliant version ensures at least one actual call (or removes the unused definition).

## 05. Function template defined but never instantiated/called
- **Seed:** `03_member_function_never_called.cpp`
- **Non-compliant:** `05_function_template_never_called_noncompliant.cpp`
- **Compliant:** `05_function_template_never_called_compliant.cpp`
- **Rationale:** Rule 0-1-10 requires every defined function to be called; the compliant version ensures at least one actual call (or removes the unused definition).

## 06. Function in anonymous namespace never called
- **Seed:** `03_placeholder_never_called.cpp`
- **Non-compliant:** `06_anonymous_namespace_never_called_noncompliant.cpp`
- **Compliant:** `06_anonymous_namespace_never_called_compliant.cpp`
- **Rationale:** Rule 0-1-10 requires every defined function to be called; the compliant version ensures at least one actual call (or removes the unused definition).

## 07. Inline function never called
- **Seed:** `04_placeholder_never_called.cpp`
- **Non-compliant:** `07_inline_function_never_called_noncompliant.cpp`
- **Compliant:** `07_inline_function_never_called_compliant.cpp`
- **Rationale:** Rule 0-1-10 requires every defined function to be called; the compliant version ensures at least one actual call (or removes the unused definition).

## 08. Overload set with one overload never called
- **Seed:** `04_virtual_override_never_called.cpp`
- **Non-compliant:** `08_overload_one_unused_noncompliant.cpp`
- **Compliant:** `08_overload_one_unused_compliant.cpp`
- **Rationale:** Rule 0-1-10 requires every defined function to be called; the compliant version ensures at least one actual call (or removes the unused definition).

## 09. Operator overload defined but never used
- **Seed:** `05_function_template_never_called.cpp`
- **Non-compliant:** `09_operator_overload_never_used_noncompliant.cpp`
- **Compliant:** `09_operator_overload_never_used_compliant.cpp`
- **Rationale:** Rule 0-1-10 requires every defined function to be called; the compliant version ensures at least one actual call (or removes the unused definition).

## 10. Friend function defined but never used
- **Seed:** `05_placeholder_never_called.cpp`
- **Non-compliant:** `10_friend_function_never_used_noncompliant.cpp`
- **Compliant:** `10_friend_function_never_used_compliant.cpp`
- **Rationale:** Rule 0-1-10 requires every defined function to be called; the compliant version ensures at least one actual call (or removes the unused definition).

## 11. Static member function never called
- **Seed:** `06_anonymous_namespace_never_called.cpp`
- **Non-compliant:** `11_static_member_function_never_called_noncompliant.cpp`
- **Compliant:** `11_static_member_function_never_called_compliant.cpp`
- **Rationale:** Rule 0-1-10 requires every defined function to be called; the compliant version ensures at least one actual call (or removes the unused definition).

## 12. Namespaced function never called
- **Seed:** `06_placeholder_never_called.cpp`
- **Non-compliant:** `12_namespaced_function_never_called_noncompliant.cpp`
- **Compliant:** `12_namespaced_function_never_called_compliant.cpp`
- **Rationale:** Rule 0-1-10 requires every defined function to be called; the compliant version ensures at least one actual call (or removes the unused definition).

## 13. Function intended for function pointer target never called
- **Seed:** `07_inline_function_never_called.cpp`
- **Non-compliant:** `13_funptr_target_never_called_noncompliant.cpp`
- **Compliant:** `13_funptr_target_never_called_compliant.cpp`
- **Rationale:** Rule 0-1-10 requires every defined function to be called; the compliant version ensures at least one actual call (or removes the unused definition).

## 14. Recursive function never called
- **Seed:** `07_placeholder_never_called.cpp`
- **Non-compliant:** `14_recursive_function_never_called_noncompliant.cpp`
- **Compliant:** `14_recursive_function_never_called_compliant.cpp`
- **Rationale:** Rule 0-1-10 requires every defined function to be called; the compliant version ensures at least one actual call (or removes the unused definition).

## 15. Functor (operator()) defined but never called
- **Seed:** `08_overload_one_unused.cpp`
- **Non-compliant:** `15_functor_call_operator_never_called_noncompliant.cpp`
- **Compliant:** `15_functor_call_operator_never_called_compliant.cpp`
- **Rationale:** Rule 0-1-10 requires every defined function to be called; the compliant version ensures at least one actual call (or removes the unused definition).

## 16. Template class member function defined but never called
- **Seed:** `08_placeholder_never_called.cpp`
- **Non-compliant:** `16_template_class_member_never_called_noncompliant.cpp`
- **Compliant:** `16_template_class_member_never_called_compliant.cpp`
- **Rationale:** Rule 0-1-10 requires every defined function to be called; the compliant version ensures at least one actual call (or removes the unused definition).

## 17. Free function with default parameters never called
- **Seed:** `09_operator_plus_never_used.cpp`
- **Non-compliant:** `17_free_function_with_defaults_never_called_noncompliant.cpp`
- **Compliant:** `17_free_function_with_defaults_never_called_compliant.cpp`
- **Rationale:** Rule 0-1-10 requires every defined function to be called; the compliant version ensures at least one actual call (or removes the unused definition).

## 18. extern "C" function never called
- **Seed:** `09_placeholder_never_called.cpp`
- **Non-compliant:** `18_extern_c_function_never_called_noncompliant.cpp`
- **Compliant:** `18_extern_c_function_never_called_compliant.cpp`
- **Rationale:** Rule 0-1-10 requires every defined function to be called; the compliant version ensures at least one actual call (or removes the unused definition).

## 19. Function taking references never called
- **Seed:** `10_friend_function_never_used.cpp`
- **Non-compliant:** `19_ref_params_function_never_called_noncompliant.cpp`
- **Compliant:** `19_ref_params_function_never_called_compliant.cpp`
- **Rationale:** Rule 0-1-10 requires every defined function to be called; the compliant version ensures at least one actual call (or removes the unused definition).

## 20. static inline “header-style” utility never called
- **Seed:** `10_placeholder_never_called.cpp`
- **Non-compliant:** `20_static_inline_headerstyle_never_called_noncompliant.cpp`
- **Compliant:** `20_static_inline_headerstyle_never_called_compliant.cpp`
- **Rationale:** Rule 0-1-10 requires every defined function to be called; the compliant version ensures at least one actual call (or removes the unused definition).
