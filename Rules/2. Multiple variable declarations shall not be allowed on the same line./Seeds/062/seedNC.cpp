// Context: Hydroelectric turbine blade pitch optimizer

#include <iostream>
int main(){
    float pitch=0.5F, rpm=300.0F;   // NC
    float step=0.0F, eff=0.0F;      // NC
    unsigned t=0U, alarms=0U;       // NC
    step = 0.02F; pitch += step; rpm += 2.0F;
    std::cout<<pitch<<","<<rpm<<","<<step<<","<<eff<<","<<t<<","<<alarms<<"\n";
    return 0;
}
