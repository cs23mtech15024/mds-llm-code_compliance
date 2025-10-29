// Context: Fusion reactor coolant flow monitor

#include <iostream>
int main(){
    double flow=12.0;      // C
    double set=14.0;       // C
    float k=0.6F;          // C
    float leak=0.0F;       // C
    int trips=0;           // C
    int warns=0;           // C
    flow += 0.2; leak += 0.05F;
    std::cout<<flow<<","<<set<<","<<k<<","<<leak<<","<<trips<<","<<warns<<"\n";
    return 0;
}
