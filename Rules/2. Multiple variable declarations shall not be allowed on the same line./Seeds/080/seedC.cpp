// Context: Espresso machine pressure profiler

#include <iostream>
int main(){
    float pressure=9.0F;   // C
    float temp=93.0F;      // C
    double flow=2.5;       // C
    double weight=0.0;     // C
    int shots=0;           // C
    int flushes=0;         // C
    pressure += 0.1F; shots++;
    std::cout<<pressure<<","<<temp<<","<<flow<<","<<weight<<","<<shots<<","<<flushes<<"\n";
    return 0;
}
