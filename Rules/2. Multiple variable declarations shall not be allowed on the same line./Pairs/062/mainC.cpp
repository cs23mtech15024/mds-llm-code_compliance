// Context: Volcano monitoring seismic trigger filter

// ------ Compliant Program (062_c.cpp)
// Compliant: one declarator per declaration across the file.
#include <iostream>
#include <vector>
#include <numeric>
namespace seis_062 {
    struct Win { double a; double b; }; // OK
    static double avg(const std::vector<double>& v){ return v.empty()?0.0:std::accumulate(v.begin(),v.end(),0.0)/static_cast<double>(v.size()); }
    void filter(){
        double a=0.0;                                // C
        double b=0.0;                                // C
        float thr=0.7F;                              // C
        float env=0.0F;                              // C
        int hits=0;                                  // C
        int alerts=0;                                // C
        std::vector<double> s{0.3,0.6,0.8,0.5,0.4};
        for (std::size_t i=0;i<s.size();++i){
            a = 0.6*a + 0.4*s[i]; b = 0.4*b + 0.6*s[i];
            env = static_cast<float>(0.8*env + 0.2*s[i]);
            bool trig = ((a+b)>static_cast<double>(thr)*2.0);
            if (trig){ hits++; }
            if (hits>2){ alerts++; }
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" a="<<a<<" b="<<b<<" env="<<env<<"\n"; }
        }
        std::cout<<"hits="<<hits<<" alerts="<<alerts<<" mean="<<avg(s)<<"\n";
    }
}
int main(){ seis_062::filter(); return 0; }
