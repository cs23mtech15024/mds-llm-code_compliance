// Context: Planetary habitat thermal radiator manager

#include <iostream>
int main(){
    double temp=290.0;     // C
    double tgt=295.0;      // C
    float pump=0.0F;       // C
    float valve=0.0F;      // C
    unsigned cycles=0U;    // C
    unsigned trips=0U;     // C
    pump += 0.1F; valve += 0.1F;
    std::cout<<temp<<","<<tgt<<","<<pump<<","<<valve<<","<<cycles<<","<<trips<<"\n";
    return 0;
}
