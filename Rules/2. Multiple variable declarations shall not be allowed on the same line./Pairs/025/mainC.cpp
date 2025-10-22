// Context: Subway door interlock monitor

// ------ Compliant Program (025_c.cpp)
// One declarator per declaration everywhere.
#include <iostream>
#include <string>
namespace door_025 {
    struct Status { bool left; bool right; }; // OK
    static void log(const std::string& s){ std::cout<<s<<"\n"; }
    void monitor(){
        bool left=false;                         // C
        bool right=false;                        // C
        int cycles=0;                            // C
        int errors=0;                            // C
        unsigned retries=0U;                     // C
        unsigned trips=0U;                       // C
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
