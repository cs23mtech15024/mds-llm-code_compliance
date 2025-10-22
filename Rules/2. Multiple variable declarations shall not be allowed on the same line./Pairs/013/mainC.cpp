// Context: Automated warehouse picker arm

// ------ Compliant Program (013_c.cpp)
// One declarator per declaration across the file.
#include <iostream>
#include <vector>
#include <cmath>
namespace pick_013 {
    struct Pose { float x; float y; }; // OK
    static float stepToward(float v,float t){ return v + (t-v)*0.5F; }
    void run(){
        long moves=0L;                         // C
        long retries=0L;                       // C
        float x=0.0F;                          // C
        float y=0.0F;                          // C
        bool jam=false;                        // C
        bool eStop=false;                      // C
        Pose p{0.0F,0.0F};
        std::vector<Pose> targets{{1.0F,0.0F},{1.0F,1.0F},{0.0F,1.0F}};
        for (std::size_t i=0;i<targets.size();++i){
            p.x = stepToward(p.x,targets[i].x);
            p.y = stepToward(p.y,targets[i].y);
            moves++;
            if (std::fabs(p.x-targets[i].x)>0.6F){ retries++; jam=true; }
            if ((i==2U)&&jam){ eStop=true; }
            if ((i%1U)==0U){ std::cout<<"i="<<i<<" x="<<p.x<<" y="<<p.y<<" jam="<<jam<<"\n"; }
        }
        std::cout<<"moves="<<moves<<" retries="<<retries<<" eStop="<<eStop<<"\n";
    }
}
int main(){ pick_013::run(); return 0; }
