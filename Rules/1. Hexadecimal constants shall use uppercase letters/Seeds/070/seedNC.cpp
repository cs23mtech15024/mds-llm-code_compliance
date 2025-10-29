// Context: Compiler AST node type identifier

// Seed 084 — NC: lowercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint16_t node_type=0xabcd; // NC
    std::cout << "ast=0x" << std::hex << node_type << "\n";
    return 0;
}