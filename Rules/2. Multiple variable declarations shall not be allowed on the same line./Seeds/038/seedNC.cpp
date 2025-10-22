// Context: Autonomous mower boundary tracker

#include <iostream>
int main(){
    float north=0.0F, east=0.0F;     // NC
    float speed=0.5F, turn=0.0F;     // NC
    unsigned hits=0U, warns=0U;      // NC
    north += 0.2F; east += 0.1F;
    std::cout<<north<<","<<east<<","<<speed<<","<<turn<<","<<hits<<","<<warns<<"\n";
    return 0;
}
