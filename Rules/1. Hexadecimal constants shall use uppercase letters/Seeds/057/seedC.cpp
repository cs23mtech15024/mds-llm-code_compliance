// Context: Idle-speed offset & flag tags

// Seed 085 — C: uppercase hex offset/flag
#include <iostream>
int main(){
    unsigned offset=0x3;   // C (digits only)
    unsigned flag  =0xBE;  // C
    std::cout<<"idle off=0x"<<std::hex<<offset
             <<" flag=0x"<<flag<<"\n";
    return 0;
}