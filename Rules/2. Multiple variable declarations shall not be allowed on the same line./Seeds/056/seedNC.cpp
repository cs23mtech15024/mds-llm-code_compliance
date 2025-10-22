// Context: Swarm drone collision avoidance

#include <iostream>
int main(){
    float x=0.0F, y=0.0F;           // NC
    float vx=0.1F, vy=-0.1F;        // NC
    unsigned peers=5U, alerts=0U;   // NC
    x+=vx; y+=vy;
    std::cout<<x<<","<<y<<","<<vx<<","<<vy<<","<<peers<<","<<alerts<<"\n";
    return 0;
}
