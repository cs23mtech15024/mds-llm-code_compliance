// Context: Surgical robot force threshold guardian

// ------ Non-Compliant Program (073_nc.cpp)
// 8-0-1 violations: multiple declarators per declaration (// NC).
#include <iostream>
#include <vector>
#include <cmath>
namespace surg_073 {
    struct Force { float fx; float fz; }; // OK
    static float clampf(float v,float m){ return std::max(-m,std::min(m,v)); }
    void guard(){
        float fz=0.0F, fx=0.0F;                // NC
        float limit=4.0F, margin=0.5F;         // NC
        unsigned events=0U, trips=0U;          // NC
        std::vector<float> seq{0.8F,1.3F,2.0F,1.0F,3.7F,4.2F};
        for (std::size_t i=0;i<seq.size();++i){
            fz = clampf(fz + 0.6F*seq[i], 0.0F);
            fx = clampf(fx + 0.2F*seq[i], 0.0F);
            float safe = limit - margin;
            if (fz>safe){ trips++; fz = safe; }
            events++;
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" fz="<<fz<<" fx="<<fx<<"\n"; }
        }
        std::cout<<"events="<<events<<" trips="<<trips<<"\n";
    }
}
int main(){ surg_073::guard(); return 0; }
