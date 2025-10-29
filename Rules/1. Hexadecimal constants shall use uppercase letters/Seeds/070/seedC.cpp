// Context: Compiler AST node type identifier

// Seed 084 — C: uppercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint16_t node_type=0xABCD; // C
    std::cout << "ast=0x" << std::hex << node_type << "\n";
    return 0;
}