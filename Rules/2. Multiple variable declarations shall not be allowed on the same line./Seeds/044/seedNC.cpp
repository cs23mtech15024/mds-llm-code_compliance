// Context: Smart building elevator load leveler

#include <iostream>
int main(){
    int load=0, limit=1200;          // NC
    float bias=0.0F, rate=0.0F;      // NC
    bool slow=false, stop=false;     // NC
    load+=200; bias+=0.1F;
    std::cout<<load<<","<<limit<<","<<bias<<","<<rate<<","<<slow<<","<<stop<<"\n";
    return 0;
}
