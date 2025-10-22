// Context: Smart building elevator load leveler

#include <iostream>
int main(){
    int load=0;            // C
    int limit=1200;        // C
    float bias=0.0F;       // C
    float rate=0.0F;       // C
    bool slow=false;       // C
    bool stop=false;       // C
    load+=200; bias+=0.1F;
    std::cout<<load<<","<<limit<<","<<bias<<","<<rate<<","<<slow<<","<<stop<<"\n";
    return 0;
}
