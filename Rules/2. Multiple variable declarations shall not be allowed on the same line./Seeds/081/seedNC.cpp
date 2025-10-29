// Context: Plasma cutter torch height controller

#include <iostream>
int main(){
    float height=3.0F, voltage=120.0F;    // NC
    float speed=100.0F, current=45.0F;    // NC
    int pierces=0, errors=0;              // NC
    height += 0.1F; pierces++;
    std::cout<<height<<","<<voltage<<","<<speed<<","<<current<<","<<pierces<<","<<errors<<"\n";
    return 0;
}
