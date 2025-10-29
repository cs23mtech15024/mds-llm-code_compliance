// Context: Industrial freezer temperature guard

#include <iostream>
int main(){
    double tA=-18.0;     // C
    double tB=-19.5;     // C
    float drift=0.0F;    // C
    float slope=0.0F;    // C
    int open=0;          // C
    int alerts=0;        // C
    drift += 0.2F; slope = -0.05F;
    std::cout<<tA<<","<<tB<<","<<drift<<","<<slope<<","<<open<<","<<alerts<<"\n";
    return 0;
}
