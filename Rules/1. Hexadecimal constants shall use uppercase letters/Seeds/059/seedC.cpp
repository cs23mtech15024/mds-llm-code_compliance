// Context: T/W mass & tag mask

// Seed 091 — C: uppercase hex mass/mask
#include <iostream>
int main(){
    unsigned mass=0x190;  // C (digits only)
    unsigned mask=0x7F;   // C
    std::cout<<"tw mass=0x"<<std::hex<<mass
             <<" mask=0x"<<mask<<"\n";
    return 0;
}