// Context: UAV camera gimbal stabilizer

#include <iostream>
int main(){
    float roll=0.0F, pitch=0.0F;      // NC
    float yaw=0.0F, drift=0.0F;       // NC
    unsigned frames=0U, drops=0U;     // NC
    roll+=0.01F; yaw-=0.01F;
    std::cout<<roll<<","<<pitch<<","<<yaw<<","<<drift<<","<<frames<<","<<drops<<"\n";
    return 0;
}
