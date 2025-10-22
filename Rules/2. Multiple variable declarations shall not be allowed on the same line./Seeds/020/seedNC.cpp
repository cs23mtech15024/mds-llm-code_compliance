// Context: Satellite power system balancer

#include <iostream>
int main(){
    double wA=120.0, wB=118.0;        // NC
    double wC=121.5, margin=0.0;      // NC
    int flips=0, limitHits=0;         // NC
    margin = (wA+wB+wC)/3.0;
    std::cout<<margin<<","<<flips<<","<<limitHits<<"\n";
    return 0;
}
