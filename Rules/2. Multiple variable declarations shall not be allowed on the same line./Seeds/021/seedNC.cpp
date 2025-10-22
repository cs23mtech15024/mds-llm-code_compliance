// Context: Warehouse AGV path follower

#include <iostream>
int main(){
    float x=0.0F, y=0.0F;        // NC
    float vx=0.1F, vy=0.0F;      // NC
    unsigned steps=0U, maxS=3U;  // NC
    x+=vx; y+=vy;
    std::cout<<x<<","<<y<<","<<vx<<","<<vy<<","<<steps<<","<<maxS<<"\n";
    return 0;
}
