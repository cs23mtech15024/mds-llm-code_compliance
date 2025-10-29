// Context: CNC mill spindle speed controller

#include <iostream>
int main(){
    float rpm=1000.0F, load=0.0F;         // NC
    float feedRate=100.0F, depth=2.0F;    // NC
    int tools=8, changes=0;               // NC
    rpm += 10.0F; changes++;
    std::cout<<rpm<<","<<load<<","<<feedRate<<","<<depth<<","<<tools<<","<<changes<<"\n";
    return 0;
}
