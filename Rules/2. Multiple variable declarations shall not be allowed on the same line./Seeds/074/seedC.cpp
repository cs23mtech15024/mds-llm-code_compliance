// Context: Smart dam spillway gate scheduler

#include <iostream>
int main(){
    double level=7.2;      // C
    double set=6.8;        // C
    float open=0.0F;       // C
    float rate=0.0F;       // C
    int alerts=0;          // C
    int cycles=0;          // C
    open += 0.1F; level -= 0.2;
    std::cout<<level<<","<<set<<","<<open<<","<<rate<<","<<alerts<<","<<cycles<<"\n";
    return 0;
}
