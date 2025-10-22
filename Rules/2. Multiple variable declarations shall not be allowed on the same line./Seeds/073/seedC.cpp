// Context: Surgical robot force threshold guardian

#include <iostream>
int main(){
    float fz=0.0F;        // C
    float fx=0.0F;        // C
    float limit=4.0F;     // C
    float margin=0.5F;    // C
    unsigned events=0U;   // C
    unsigned trips=0U;    // C
    fz += 0.4F; fx += 0.2F;
    std::cout<<fz<<","<<fx<<","<<limit<<","<<margin<<","<<events<<","<<trips<<"\n";
    return 0;
}
