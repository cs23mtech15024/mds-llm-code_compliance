// Context: Warehouse HVAC damper controller

#include <iostream>
int main(){
    float open=0.2F;     // C
    float rate=0.0F;     // C
    bool heat=false;     // C
    bool cool=false;     // C
    int cmd=0;           // C
    int alarms=0;        // C
    open += 0.1F; rate += 0.05F;
    std::cout<<open<<","<<rate<<","<<heat<<","<<cool<<","<<cmd<<","<<alarms<<"\n";
    return 0;
}
