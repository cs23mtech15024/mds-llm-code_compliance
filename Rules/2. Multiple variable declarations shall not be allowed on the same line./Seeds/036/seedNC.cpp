// Context: Hospital negative-pressure room monitor

#include <iostream>
int main(){
    double pa=-5.0, target=-8.0;     // NC
    float flow=0.0F, leak=0.0F;      // NC
    int alarms=0, warns=0;           // NC
    flow += 0.2F; pa -= 0.3;
    std::cout<<pa<<","<<target<<","<<flow<<","<<leak<<","<<alarms<<","<<warns<<"\n";
    return 0;
}
