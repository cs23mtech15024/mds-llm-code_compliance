// Context: Satellite power system balancer

#include <iostream>
int main(){
    double wA=120.0;      // C
    double wB=118.0;      // C
    double wC=121.5;      // C
    double margin=0.0;    // C
    int flips=0;          // C
    int limitHits=0;      // C
    margin = (wA+wB+wC)/3.0;
    std::cout<<margin<<","<<flips<<","<<limitHits<<"\n";
    return 0;
}
