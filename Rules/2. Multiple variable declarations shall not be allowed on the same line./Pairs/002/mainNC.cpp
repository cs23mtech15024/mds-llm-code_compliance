// Context: Factory conveyor motor watchdog

// ------ Non-Compliant Program (002_nc.cpp)
// Intentional 8-0-1 violations via multiple declarators.
#include <iostream>
#include <string>
#include <cstdint>
namespace wd_002 {
    struct Event { int code; std::string msg; }; // OK
    static void log(const Event& e){ std::cout<<"event code="<<e.code<<" msg="<<e.msg<<"\n"; }
    void run(){
        unsigned tick=0U, reset=0U;             // NC
        int lastCode=0, failCode=-1;            // NC
        bool enabled=true, tripped=false;       // NC
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
