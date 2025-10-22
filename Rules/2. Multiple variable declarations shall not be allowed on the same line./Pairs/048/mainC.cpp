// Context: Wind farm wake interaction analyzer

// ------ Compliant Program (048_c.cpp)
// One declarator per declaration (MISRA C++ 8-0-1 compliant).
#include <iostream>
#include <vector>
#include <numeric>
namespace wake_048 {
    struct Turb { double v1; double v2; }; // OK
    double mean(const std::vector<double>& x){ return x.empty()?0.0:std::accumulate(x.begin(),x.end(),0.0)/static_cast<double>(x.size()); }
    void analyze(){
        double v1=9.0;                          // C
        double v2=8.5;                          // C
        float kd=0.05F;                          // C
        float ct=0.8F;                           // C
        int rows=2;                               // C
        int cols=3;                               // C
        Turb t{v1,v2};
        std::vector<double> out;
        for (int r=0;r<rows;++r){
            for (int c=0;c<cols;++c){
                t.v2 = v2 - static_cast<double>(kd)*static_cast<double>(c) - (ct-0.5F)*0.3;
                out.push_back(t.v2);
            }
        }
        std::cout<<"v2_mean="<<mean(out)<<" kd="<<kd<<" ct="<<ct<<"\n";
    }
}
int main(){ wake_048::analyze(); return 0; }
