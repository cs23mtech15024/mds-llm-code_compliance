// Context: Data center hot-aisle containment fan control

#include <iostream>
int main(){
    double tin=28.0, tout=32.0;     // NC
    float fan=0.0F, damper=0.0F;    // NC
    unsigned steps=0U, trips=0U;    // NC
    fan += 0.2F; tout -= 0.3;
    std::cout<<tin<<","<<tout<<","<<fan<<","<<damper<<","<<steps<<","<<trips<<"\n";
    return 0;
}
