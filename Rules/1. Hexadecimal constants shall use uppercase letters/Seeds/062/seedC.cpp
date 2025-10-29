// Context: Turbulence ref & mask

// Seed 096 — C: uppercase hex ref/mask
#include <iostream>
int main(){
    unsigned ref =0x17;  // C (digits only)
    unsigned mask=0x7A;  // C
    std::cout<<"turb ref=0x"<<std::hex<<ref
             <<" mask=0x"<<mask<<"\n";
    return 0;
}