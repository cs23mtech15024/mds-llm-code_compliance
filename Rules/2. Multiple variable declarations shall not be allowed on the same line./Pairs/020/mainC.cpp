// Context: Satellite power system balancer

// ------ Compliant Program (020_c.cpp)
// Compliant: single declarator per declaration throughout.
#include <iostream>
#include <vector>
#include <numeric>
namespace sat_020 {
    struct Channel { double w; }; // OK
    static double mean(const std::vector<Channel>& v){ return v.empty()?0.0:std::accumulate(v.begin(),v.end(),0.0,[](double a,const Channel& c){return a+c.w;})/static_cast<double>(v.size()); }
    void balance(){
        double wA=120.0;                       // C
        double wB=118.0;                       // C
        double wC=121.5;                       // C
        double margin=0.0;                      // C
        int flips=0;                            // C
        int limitHits=0;                        // C
        std::vector<Channel> ch{{120.0},{118.0},{121.5}};
        margin = (wA+wB+wC)/3.0;
        if (margin>120.5){ flips++; }
        std::cout<<"avg="<<margin<<" flips="<<flips<<" lim="<<limitHits<<" mean="<<mean(ch)<<"\n";
    }
}
int main(){ sat_020::balance(); return 0; }
