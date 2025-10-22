// Context: Fusion reactor coolant flow monitor

#include <iostream>
int main(){
    double flow=12.0, set=14.0;      // NC
    float k=0.6F, leak=0.0F;         // NC
    int trips=0, warns=0;            // NC
    flow += 0.2; leak += 0.05F;
    std::cout<<flow<<","<<set<<","<<k<<","<<leak<<","<<trips<<","<<warns<<"\n";
    return 0;
}
