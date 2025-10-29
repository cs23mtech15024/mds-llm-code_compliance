// Context: Electric ferry docking thruster coordinator

#include <iostream>
int main(){
    float fx=0.0F, fy=0.0F;          // NC
    float yaw=0.0F, gain=0.8F;       // NC
    unsigned steps=0U, faults=0U;    // NC
    fx += 0.2F; fy -= 0.1F;
    yaw += 0.05F; steps++;
    std::cout<<fx<<","<<fy<<","<<yaw<<","<<gain<<","<<steps<<","<<faults<<"\n";
    return 0;
}
