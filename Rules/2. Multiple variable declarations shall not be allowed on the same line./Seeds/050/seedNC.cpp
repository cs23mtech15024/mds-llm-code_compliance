// Context: Planetary habitat thermal radiator manager

#include <iostream>
int main(){
    double temp=290.0, tgt=295.0;    // NC
    float pump=0.0F, valve=0.0F;     // NC
    unsigned cycles=0U, trips=0U;    // NC
    pump += 0.1F; valve += 0.1F;
    std::cout<<temp<<","<<tgt<<","<<pump<<","<<valve<<","<<cycles<<","<<trips<<"\n";
    return 0;
}
