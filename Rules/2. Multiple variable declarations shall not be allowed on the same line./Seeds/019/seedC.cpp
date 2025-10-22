// Context: Autonomous car lane departure alert

#include <iostream>
int main(){
    float lateral=0.0F;     // C
    float yawRate=0.0F;     // C
    unsigned frames=0U;     // C
    unsigned alarms=0U;     // C
    bool left=false;        // C
    bool right=false;       // C
    lateral+=0.2F; yawRate=0.03F;
    std::cout<<lateral<<","<<yawRate<<","<<frames<<","<<alarms<<","<<left<<","<<right<<"\n";
    return 0;
}
