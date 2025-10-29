// Context: Oil refinery cracking tower monitor

#include <iostream>
int main(){
    float temp=450.0F, pressure=20.0F;    // NC
    double throughput=0.0, efficiency=0.0; // NC
    unsigned trays=40U, alarms=0U;        // NC
    temp += 1.0F; trays++;
    std::cout<<temp<<","<<pressure<<","<<throughput<<","<<efficiency<<","<<trays<<","<<alarms<<"\n";
    return 0;
}
