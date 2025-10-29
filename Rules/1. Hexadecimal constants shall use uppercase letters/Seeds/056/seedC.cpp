// Context: Radar mode & frame mask tags

// Seed 084 — C: uppercase hex mode/frame
#include <iostream>
int main(){
    unsigned mode =0xC;    // C
    unsigned frame=0x7F;   // C
    std::cout<<"radar mode=0x"<<std::hex<<mode
             <<" frame=0x"<<frame<<"\n";
    return 0;
}