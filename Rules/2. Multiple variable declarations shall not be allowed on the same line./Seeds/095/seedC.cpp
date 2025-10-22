// Context: Hydroelectric turbine blade pitch optimizer

#include <iostream>
int main(){
    float pitch=0.5F;     // C
    float rpm=300.0F;     // C
    float step=0.0F;      // C
    float eff=0.0F;       // C
    unsigned t=0U;        // C
    unsigned alarms=0U;   // C
    step = 0.02F; pitch += step; rpm += 2.0F;
    std::cout<<pitch<<","<<rpm<<","<<step<<","<<eff<<","<<t<<","<<alarms<<"\n";
    return 0;
}
