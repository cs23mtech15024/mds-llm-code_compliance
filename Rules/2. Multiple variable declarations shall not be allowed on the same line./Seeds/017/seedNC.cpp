// Context: Industrial freezer temperature guard

#include <iostream>
int main(){
    double tA=-18.0, tB=-19.5;       // NC
    float drift=0.0F, slope=0.0F;    // NC
    int open=0, alerts=0;            // NC
    drift += 0.2F; slope = -0.05F;
    std::cout<<tA<<","<<tB<<","<<drift<<","<<slope<<","<<open<<","<<alerts<<"\n";
    return 0;
}
