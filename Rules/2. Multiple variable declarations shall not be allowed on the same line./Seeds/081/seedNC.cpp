// Context: Autonomous harbor oil spill skimmer route planner

#include <iostream>
int main(){
    float x=0.0F, y=0.0F;          // NC
    float vx=0.0F, vy=0.0F;        // NC
    unsigned tasks=0U, alerts=0U;  // NC
    vx += 0.3F; vy -= 0.1F; x+=vx; y+=vy;
    std::cout<<x<<","<<y<<","<<vx<<","<<vy<<","<<tasks<<","<<alerts<<"\n";
    return 0;
}
