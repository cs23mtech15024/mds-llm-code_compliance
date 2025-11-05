// Context: Timeout duration setter

// Seed 035 — C: parameter without underscore prefix
#include <iostream>
void set_timeout(long ms) { // C
    std::cout << "timeout=" << ms << "ms\n";
}
int main(){
    set_timeout(5000);
    return 0;
}