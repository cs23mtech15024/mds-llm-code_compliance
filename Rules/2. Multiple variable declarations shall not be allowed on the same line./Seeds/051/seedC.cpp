// Context: Urban traffic adaptive signal phasing

#include <iostream>
int main(){
    unsigned north=12U;   // C
    unsigned east=8U;     // C
    float bias=0.4F;      // C
    float gain=0.2F;      // C
    int cycles=0;         // C
    int holds=0;          // C
    bias += 0.1F; north += 1U;
    std::cout<<north<<","<<east<<","<<bias<<","<<gain<<","<<cycles<<","<<holds<<"\n";
    return 0;
}
