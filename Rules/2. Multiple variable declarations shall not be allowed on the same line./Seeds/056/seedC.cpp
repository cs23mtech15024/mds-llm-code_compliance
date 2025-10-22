// Context: Swarm drone collision avoidance

#include <iostream>
int main(){
    float x=0.0F;          // C
    float y=0.0F;          // C
    float vx=0.1F;         // C
    float vy=-0.1F;        // C
    unsigned peers=5U;     // C
    unsigned alerts=0U;    // C
    x+=vx; y+=vy;
    std::cout<<x<<","<<y<<","<<vx<<","<<vy<<","<<peers<<","<<alerts<<"\n";
    return 0;
}
