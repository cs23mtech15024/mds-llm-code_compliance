// Context: Smart irrigation moisture guard

// ------ Non-Compliant Program (035_nc.cpp)
// Shows 8-0-1 violations through grouped declarators.
#include <iostream>
#include <vector>
namespace irr_035 {
    struct Sample { float soil; float thr; }; // OK
    void guard(){
        float soil=0.35F, thresh=0.30F;        // NC
        bool valve=false, alert=false;         // NC
        unsigned polls=0U, drops=0U;           // NC
        std::vector<float> hist{0.34F,0.33F,0.29F,0.31F};
        for (std::size_t i=0;i<hist.size();++i){
            soil = hist[i]; polls++;
            valve = (soil<thresh);
            if (valve){ alert=true; }
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" soil="<<soil<<" valve="<<valve<<"\n"; }
        }
        std::cout<<"polls="<<polls<<" drops="<<drops<<" alert="<<alert<<"\n";
    }
}
int main(){ irr_035::guard(); return 0; }
