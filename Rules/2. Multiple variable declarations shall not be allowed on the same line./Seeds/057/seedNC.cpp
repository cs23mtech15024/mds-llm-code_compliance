// Context: Solar tracker dual-axis alignment

#include <iostream>
int main(){
    float az=0.0F, el=0.0F;         // NC
    float azRate=0.0F, elRate=0.0F; // NC
    unsigned faults=0U, moves=0U;   // NC
    az+=0.2F; el+=0.1F; moves++;
    std::cout<<az<<","<<el<<","<<azRate<<","<<elRate<<","<<faults<<","<<moves<<"\n";
    return 0;
}
