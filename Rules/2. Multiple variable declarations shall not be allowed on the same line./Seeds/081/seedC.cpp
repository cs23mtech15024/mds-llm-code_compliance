// Context: Plasma cutter torch height controller

#include <iostream>
int main(){
    float height=3.0F;     // C
    float voltage=120.0F;  // C
    float speed=100.0F;    // C
    float current=45.0F;   // C
    int pierces=0;         // C
    int errors=0;          // C
    height += 0.1F; pierces++;
    std::cout<<height<<","<<voltage<<","<<speed<<","<<current<<","<<pierces<<","<<errors<<"\n";
    return 0;
}
