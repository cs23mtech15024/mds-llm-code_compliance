// Context: Timeout duration setter

// Seed 035 — NC: parameter starts with underscore
#include <iostream>
void set_timeout(long _ms) { // NC
    std::cout << "timeout=" << _ms << "ms\n";
}
int main(){
    set_timeout(5000);
    return 0;
}