// Context: Deep-sea ROV depth and ballast control

// ------ Non-Compliant Program (039_nc.cpp)
// Groups declarators; violates 8-0-1.
#include <iostream>
#include <vector>
namespace rov_039 {
    struct Ballast { double depth; double mass; }; // OK
    void dive(){
        double depth=10.0, ballast=0.0;        // NC
        bool blow=false, flood=false;          // NC
        unsigned cycles=0U, alarms=0U;         // NC
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
