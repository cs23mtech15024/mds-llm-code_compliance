// Context: Automotive CAN diagnostics poller

// ------ Non-Compliant Program (008_nc.cpp)
// Uses multiple declarators in single declarations (8-0-1 violation).
#include <iostream>
#include <vector>
#include <cstdint>
namespace can_008 {
    struct Frame { unsigned id; std::vector<unsigned char> data; }; // OK
    void poll(){
        unsigned req=0U, resp=0U;        // NC
        int err=0, retries=0;            // NC
        bool ok=false, timeout=false;    // NC
        Frame f{0x7E0U, {0x01,0x0D}};
        for (int i=0;i<3;++i){ req++; if (i==2){ resp++; ok=true; } else { retries++; } }
        if (resp==0U){ timeout=true; err=1; }
        std::cout<<"req="<<req<<" resp="<<resp<<" err="<<err<<" retries="<<retries
                 <<" ok="<<ok<<" to="<<timeout<<"\n";
    }
}
int main(){ can_008::poll(); return 0; }
