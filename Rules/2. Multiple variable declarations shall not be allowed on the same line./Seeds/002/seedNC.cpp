// Context: Factory conveyor motor watchdog

#include <iostream>
int main(){
    unsigned tick=0U, reset=0U; // NC
    int lastCode=0, failCode=-1; // NC
    bool enabled=true, tripped=false; // NC
    std::cout<<tick<<","<<reset<<","<<lastCode<<","<<failCode<<","<<enabled<<","<<tripped<<"\n";
    return 0;
}
