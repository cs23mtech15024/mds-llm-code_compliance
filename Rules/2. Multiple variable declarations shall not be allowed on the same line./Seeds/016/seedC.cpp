// Context: UAV camera gimbal stabilizer

#include <iostream>
int main(){
    float roll=0.0F;        // C
    float pitch=0.0F;       // C
    float yaw=0.0F;         // C
    float drift=0.0F;       // C
    unsigned frames=0U;     // C
    unsigned drops=0U;      // C
    roll+=0.01F; yaw-=0.01F;
    std::cout<<roll<<","<<pitch<<","<<yaw<<","<<drift<<","<<frames<<","<<drops<<"\n";
    return 0;
}
