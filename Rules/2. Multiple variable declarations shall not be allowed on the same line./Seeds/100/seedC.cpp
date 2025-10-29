// Context: Oil refinery cracking tower monitor

#include <iostream>
int main(){
    float temp=450.0F;         // C
    float pressure=20.0F;      // C
    double throughput=0.0;     // C
    double efficiency=0.0;     // C
    unsigned trays=40U;        // C
    unsigned alarms=0U;        // C
    temp += 1.0F; trays++;
    std::cout<<temp<<","<<pressure<<","<<throughput<<","<<efficiency<<","<<trays<<","<<alarms<<"\n";
    return 0;
}
