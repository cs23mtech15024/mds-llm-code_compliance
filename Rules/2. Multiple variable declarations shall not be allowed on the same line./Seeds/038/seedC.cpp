// Context: Autonomous mower boundary tracker

#include <iostream>
int main(){
    float north=0.0F;     // C
    float east=0.0F;      // C
    float speed=0.5F;     // C
    float turn=0.0F;      // C
    unsigned hits=0U;     // C
    unsigned warns=0U;    // C
    north += 0.2F; east += 0.1F;
    std::cout<<north<<","<<east<<","<<speed<<","<<turn<<","<<hits<<","<<warns<<"\n";
    return 0;
}
