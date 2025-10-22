// Context: High-speed rail pantograph contact monitor

#include <iostream>
int main(){
    float force=0.0F, rate=0.0F;    // NC
    float thr=90.0F, margin=5.0F;   // NC
    unsigned hits=0U, alarms=0U;    // NC
    force += 4.0F; if(force>thr){ ++hits; }
    std::cout<<force<<","<<rate<<","<<thr<<","<<margin<<","<<hits<<","<<alarms<<"\n";
    return 0;
}
