// Context: Factory conveyor motor watchdog

#include <iostream>
int main(){
    unsigned tick=0U;     // C
    unsigned reset=0U;    // C
    int lastCode=0;       // C
    int failCode=-1;      // C
    bool enabled=true;    // C
    bool tripped=false;   // C
    std::cout<<tick<<","<<reset<<","<<lastCode<<","<<failCode<<","<<enabled<<","<<tripped<<"\n";
    return 0;
}
