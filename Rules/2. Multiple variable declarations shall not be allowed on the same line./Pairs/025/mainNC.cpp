// Context: Subway door interlock monitor

// ------ Non-Compliant Program (025_nc.cpp)
// Grouped declarators (// NC) create 8-0-1 violations.
#include <iostream>
#include <string>
namespace door_025 {
    struct Status { bool left; bool right; }; // OK
    static void log(const std::string& s){ std::cout<<s<<"\n"; }
    void monitor(){
        bool left=false, right=false;          // NC
        int cycles=0, errors=0;                // NC
        unsigned retries=0U, trips=0U;         // NC
        Status st{false,false};
        for (unsigned i=0U;i<6U;++i){
            cycles++; left = (i%2U==0U); right = !left; if (!left && !right){ errors++; }
            if ((i%3U)==0U){ retries++; }
            if (left&&right){ trips++; log("interlock trip"); }
        }
        std::cout<<"c="<<cycles<<" e="<<errors<<" r="<<retries<<" t="<<trips<<"\n";
    }
}
int main(){ door_025::monitor(); return 0; }
