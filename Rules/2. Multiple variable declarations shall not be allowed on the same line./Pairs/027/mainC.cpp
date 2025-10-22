// Context: Airport baggage sorter diverter

// ------ Compliant Program (027_c.cpp)
// Single declarator per declaration throughout (8-0-1 compliant).
#include <iostream>
#include <vector>
namespace bag_027 {
    struct Lane { unsigned id; bool jam; }; // OK
    void step(){
        unsigned bags=0U;                      // C
        unsigned jam=0U;                       // C
        float speed=1.0F;                      // C
        float accel=0.0F;                      // C
        bool divert=false;                     // C
        bool halt=false;                        // C
        std::vector<Lane> lanes{{1,false},{2,false}};
        for (unsigned i=0U;i<6U;++i){
            bags+=2U; accel = (i%2U==0U)?0.1F:-0.1F; speed += accel;
            if (speed<0.5F){ halt=true; }
            if ((i%3U)==2U){ jam++; lanes[1].jam=true; divert=true; }
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" spd="<<speed<<" jam="<<jam<<" div="<<divert<<"\n"; }
        }
        std::cout<<"bags="<<bags<<" jam="<<jam<<" halt="<<halt<<"\n";
    }
}
int main(){ bag_027::step(); return 0; }
