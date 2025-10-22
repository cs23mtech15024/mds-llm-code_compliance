// Context: Urban traffic adaptive signal phasing

#include <iostream>
int main(){
    unsigned north=12U, east=8U;   // NC
    float bias=0.4F, gain=0.2F;    // NC
    int cycles=0, holds=0;         // NC
    bias += 0.1F; north += 1U;
    std::cout<<north<<","<<east<<","<<bias<<","<<gain<<","<<cycles<<","<<holds<<"\n";
    return 0;
}
