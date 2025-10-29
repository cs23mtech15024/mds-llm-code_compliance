// Context: Hospital negative-pressure room monitor

#include <iostream>
int main(){
    double pa=-5.0;      // C
    double target=-8.0;  // C
    float flow=0.0F;     // C
    float leak=0.0F;     // C
    int alarms=0;        // C
    int warns=0;         // C
    flow += 0.2F; pa -= 0.3;
    std::cout<<pa<<","<<target<<","<<flow<<","<<leak<<","<<alarms<<","<<warns<<"\n";
    return 0;
}
