// Context: CNC mill spindle speed controller

#include <iostream>
int main(){
    float rpm=1000.0F;     // C
    float load=0.0F;       // C
    float feedRate=100.0F; // C
    float depth=2.0F;      // C
    int tools=8;           // C
    int changes=0;         // C
    rpm += 10.0F; changes++;
    std::cout<<rpm<<","<<load<<","<<feedRate<<","<<depth<<","<<tools<<","<<changes<<"\n";
    return 0;
}
