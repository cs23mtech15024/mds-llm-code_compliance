// Context: Database connection counter

// Seed 006 — NC: static variable starts with underscore
#include <iostream>
int main(){
    static int _connection_count = 0; // NC
    _connection_count++;
    std::cout << "connections=" << _connection_count << "\n";
    return 0;
}