// Context: Prop sync delay & mask

// Seed 092 — C: uppercase hex delay/mask
#include <iostream>
int main(){
    unsigned delay=0x21;  // C (digits only)
    unsigned mask =0x0F;  // C
    std::cout<<"prop delay=0x"<<std::hex<<delay
             <<" mask=0x"<<mask<<"\n";
    return 0;
}