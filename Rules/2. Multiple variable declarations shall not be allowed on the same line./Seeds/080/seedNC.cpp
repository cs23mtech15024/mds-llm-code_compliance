// Context: Espresso machine pressure profiler

#include <iostream>
int main(){
    float pressure=9.0F, temp=93.0F;      // NC
    double flow=2.5, weight=0.0;          // NC
    int shots=0, flushes=0;               // NC
    pressure += 0.1F; shots++;
    std::cout<<pressure<<","<<temp<<","<<flow<<","<<weight<<","<<shots<<","<<flushes<<"\n";
    return 0;
}
