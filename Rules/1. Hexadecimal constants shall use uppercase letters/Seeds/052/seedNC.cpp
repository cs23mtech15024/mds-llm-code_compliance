// Context: Marine CTE base literal

// Seed 076 — NC: lowercase hex CTE base
#include <iostream>
int main(){
    long base = 0x2a; // NC: 42
    float cte = 1.75F; (void)cte;
    std::cout << "cte_base=" << base << "\n";
    return 0;
}