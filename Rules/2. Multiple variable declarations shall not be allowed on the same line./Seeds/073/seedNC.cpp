// Context: Surgical robot force threshold guardian

#include <iostream>
int main(){
    float fz=0.0F, fx=0.0F;          // NC
    float limit=4.0F, margin=0.5F;   // NC
    unsigned events=0U, trips=0U;    // NC
    fz += 0.4F; fx += 0.2F;
    std::cout<<fz<<","<<fx<<","<<limit<<","<<margin<<","<<events<<","<<trips<<"\n";
    return 0;
}
