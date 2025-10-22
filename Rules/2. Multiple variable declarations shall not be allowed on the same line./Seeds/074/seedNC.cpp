// Context: Smart dam spillway gate scheduler

#include <iostream>
int main(){
    double level=7.2, set=6.8;       // NC
    float open=0.0F, rate=0.0F;      // NC
    int alerts=0, cycles=0;          // NC
    open += 0.1F; level -= 0.2;
    std::cout<<level<<","<<set<<","<<open<<","<<rate<<","<<alerts<<","<<cycles<<"\n";
    return 0;
}
