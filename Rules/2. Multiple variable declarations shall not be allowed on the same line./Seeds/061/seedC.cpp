// Context: Electric ferry docking thruster coordinator

#include <iostream>
int main(){
    float fx=0.0F;         // C
    float fy=0.0F;         // C
    float yaw=0.0F;        // C
    float gain=0.8F;       // C
    unsigned steps=0U;     // C
    unsigned faults=0U;    // C
    fx += 0.2F; fy -= 0.1F; yaw += 0.05F; steps++;
    std::cout<<fx<<","<<fy<<","<<yaw<<","<<gain<<","<<steps<<","<<faults<<"\n";
    return 0;
}
