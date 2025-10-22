// Context: Deep-sea ROV depth and ballast control

#include <iostream>
int main(){
    double depth=10.0;     // C
    double ballast=0.0;    // C
    bool blow=false;       // C
    bool flood=false;      // C
    unsigned cycles=0U;    // C
    unsigned alarms=0U;    // C
    depth += 1.0; ballast += 0.2;
    std::cout<<depth<<","<<ballast<<","<<blow<<","<<flood<<","<<cycles<<","<<alarms<<"\n";
    return 0;
}
