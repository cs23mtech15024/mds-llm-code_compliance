// Context: Factory conveyor motor watchdog

// ------ Compliant Program (002_c.cpp)
// All declarations split to one declarator: compliant with 8-0-1.
#include <iostream>
#include <string>
#include <cstdint>
namespace wd_002 {
    struct Event { int code; std::string msg; }; // OK
    static void log(const Event& e){ std::cout<<"event code="<<e.code<<" msg="<<e.msg<<"\n"; }
    void run(){
        unsigned tick=0U;            // C
        unsigned reset=0U;           // C
        int lastCode=0;              // C
        int failCode=-1;             // C
        bool enabled=true;           // C
        bool tripped=false;          // C
        Event e{0, "OK"};
        for (unsigned i=0U;i<10U;++i){
            tick++;
            if ((i%4U)==0U){ reset++; lastCode=1; e={1,"reset"}; log(e); }
            if (enabled && (i==7U)){ tripped=true; failCode=2; e={2,"trip"}; log(e); }
            std::cout<<"i="<<i<<" t="<<tick<<" r="<<reset<<" lc="<<lastCode<<" fc="<<failCode<<"\n";
        }
        std::cout<<"final enabled="<<enabled<<" tripped="<<tripped<<"\n";
    }
}
int main(){ wd_002::run(); return 0; }
