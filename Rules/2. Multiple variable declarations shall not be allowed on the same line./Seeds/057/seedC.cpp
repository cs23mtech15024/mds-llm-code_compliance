// Context: Data center hot-aisle containment fan control

#include <iostream>
int main(){
    double tin=28.0;      // C
    double tout=32.0;     // C
    float fan=0.0F;       // C
    float damper=0.0F;    // C
    unsigned steps=0U;    // C
    unsigned trips=0U;    // C
    fan += 0.2F; tout -= 0.3;
    std::cout<<tin<<","<<tout<<","<<fan<<","<<damper<<","<<steps<<","<<trips<<"\n";
    return 0;
}
