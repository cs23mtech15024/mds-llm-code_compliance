// Context: Autonomous harbor oil spill skimmer route planner

#include <iostream>
int main(){
    float x=0.0F;        // C
    float y=0.0F;        // C
    float vx=0.0F;       // C
    float vy=0.0F;       // C
    unsigned tasks=0U;   // C
    unsigned alerts=0U;  // C
    vx += 0.3F; vy -= 0.1F; x+=vx; y+=vy;
    std::cout<<x<<","<<y<<","<<vx<<","<<vy<<","<<tasks<<","<<alerts<<"\n";
    return 0;
}
