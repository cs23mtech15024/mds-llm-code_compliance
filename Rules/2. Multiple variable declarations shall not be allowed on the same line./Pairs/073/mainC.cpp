// Context: Surgical robot force threshold guardian

// ------ Compliant Program (073_c.cpp)
// Compliant: one declarator per declaration across the file.
#include <iostream>
#include <vector>
#include <cmath>
namespace surg_073 {
    struct Force { float fx; float fz; }; // OK
    static float clampf(float v,float m){ return std::max(-m,std::min(m,v)); }
    void guard(){
        float fz=0.0F;                           // C
        float fx=0.0F;                           // C
        float limit=4.0F;                        // C
        float margin=0.5F;                       // C
        unsigned events=0U;                      // C
        unsigned trips=0U;                       // C
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
