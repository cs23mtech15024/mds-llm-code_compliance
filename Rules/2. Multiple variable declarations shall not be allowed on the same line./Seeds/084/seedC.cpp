// Context: High-speed rail pantograph contact monitor

#include <iostream>
int main(){
    float force=0.0F;     // C
    float rate=0.0F;      // C
    float thr=90.0F;      // C
    float margin=5.0F;    // C
    unsigned hits=0U;     // C
    unsigned alarms=0U;   // C
    force += 4.0F; if(force>thr){ ++hits; }
    std::cout<<force<<","<<rate<<","<<thr<<","<<margin<<","<<hits<<","<<alarms<<"\n";
    return 0;
}
