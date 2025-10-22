// Context: Warehouse HVAC damper controller

#include <iostream>
int main(){
    float open=0.2F, rate=0.0F;      // NC
    bool heat=false, cool=false;     // NC
    int cmd=0, alarms=0;            // NC
    open += 0.1F; rate += 0.05F;
    std::cout<<open<<","<<rate<<","<<heat<<","<<cool<<","<<cmd<<","<<alarms<<"\n";
    return 0;
}
