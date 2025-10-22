// Context: Autonomous car lane departure alert

#include <iostream>
int main(){
    float lateral=0.0F, yawRate=0.0F; // NC
    unsigned frames=0U, alarms=0U;    // NC
    bool left=false, right=false;     // NC
    lateral+=0.2F; yawRate=0.03F;
    std::cout<<lateral<<","<<yawRate<<","<<frames<<","<<alarms<<","<<left<<","<<right<<"\n";
    return 0;
}
