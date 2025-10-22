// Context: Satellite power system balancer

// ------ Non-Compliant Program (020_nc.cpp)
// Shows 8-0-1 violations by grouping declarators.
#include <iostream>
#include <vector>
#include <numeric>
namespace sat_020 {
    struct Channel { double w; }; // OK
    static double mean(const std::vector<Channel>& v){ return v.empty()?0.0:std::accumulate(v.begin(),v.end(),0.0,[](double a,const Channel& c){return a+c.w;})/static_cast<double>(v.size()); }
    void balance(){
        double wA=120.0, wB=118.0;            // NC
        double wC=121.5, margin=0.0;          // NC
        int flips=0, limitHits=0;             // NC
        std::vector<Channel> ch{{120.0},{118.0},{121.5}};
        margin = (wA+wB+wC)/3.0;
        if (margin>120.5){ flips++; }
        std::cout<<"avg="<<margin<<" flips="<<flips<<" lim="<<limitHits<<" mean="<<mean(ch)<<"\n";
    }
}
int main(){ sat_020::balance(); return 0; }
