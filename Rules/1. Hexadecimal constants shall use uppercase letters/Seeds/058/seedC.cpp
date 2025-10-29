// Context: Rudder offset & mask tags

// Seed 090 — C: uppercase hex offset/mask
#include <iostream>
int main(){
    unsigned offset=0xF;  // C
    unsigned mask  =0x3B; // C
    std::cout<<"rudder off=0x"<<std::hex<<offset
             <<" mask=0x"<<mask<<"\n";
    return 0;
}