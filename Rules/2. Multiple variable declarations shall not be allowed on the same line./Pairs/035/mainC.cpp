// Context: Smart irrigation moisture guard

// ------ Compliant Program (035_c.cpp)
// Compliant rewrite: single declarator per declaration.
#include <iostream>
#include <vector>
namespace irr_035 {
    struct Sample { float soil; float thr; }; // OK
    void guard(){
        float soil=0.35F;                      // C
        float thresh=0.30F;                    // C
        bool valve=false;                      // C
        bool alert=false;                      // C
        unsigned polls=0U;                     // C
        unsigned drops=0U;                     // C
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
