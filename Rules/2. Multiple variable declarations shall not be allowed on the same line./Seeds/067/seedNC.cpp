// Context: Warehouse picking robot joint limit supervisor

#include <iostream>
int main(){
    float q1=0.0F, q2=0.0F;          // NC
    float v1=0.0F, v2=0.0F;          // NC
    unsigned trips=0U, warns=0U;     // NC
    q1 += 0.5F; v1 += 0.1F;
    std::cout<<q1<<","<<q2<<","<<v1<<","<<v2<<","<<trips<<","<<warns<<"\n";
    return 0;
}
