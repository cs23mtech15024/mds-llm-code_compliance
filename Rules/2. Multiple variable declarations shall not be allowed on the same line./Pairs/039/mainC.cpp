// Context: Deep-sea ROV depth and ballast control

// ------ Compliant Program (039_c.cpp)
// Compliant variant with one declarator per declaration.
#include <iostream>
#include <vector>
namespace rov_039 {
    struct Ballast { double depth; double mass; }; // OK
    void dive(){
        double depth=10.0;                         // C
        double ballast=0.0;                        // C
        bool blow=false;                            // C
        bool flood=false;                           // C
        unsigned cycles=0U;                         // C
        unsigned alarms=0U;                         // C
        Ballast b{depth,ballast};
        for (unsigned i=0U;i<12U;++i){
            b.mass += 0.2; b.depth += 1.0;
            if (b.depth>50.0){ alarms++; blow=true; }
            if ((i%3U)==0U){ flood=!flood; }
            cycles++;
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" z="<<b.depth<<" m="<<b.mass<<" blow="<<blow<<"\n"; }
        }
        std::cout<<"cycles="<<cycles<<" alarms="<<alarms<<" flood="<<flood<<"\n";
    }
}
int main(){ rov_039::dive(); return 0; }
