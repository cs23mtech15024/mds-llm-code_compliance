// Context: Fusion reactor coolant flow monitor

// ------ Non-Compliant Program (077_nc.cpp)
// Multi-declarator declarations violate 8-0-1.
#include <iostream>
#include <vector>
#include <algorithm>
namespace fusion_077 {
    struct Loop { double flow; double set; }; // OK
    static double clampd(double v,double lo,double hi){ return std::max(lo,std::min(hi,v)); }
    void monitor(){
        double flow=12.0, set=14.0;            // NC
        float k=0.6F, leak=0.0F;               // NC
        int trips=0, warns=0;                  // NC
        std::vector<double> d{0.4,0.2,-0.8,0.1,0.6,1.2,-0.3};
        for (std::size_t i=0;i<d.size();++i){
            flow = clampd(flow + d[i] - static_cast<double>(leak), 8.0, 20.0);
            if (flow>16.0 || flow<10.0){ trips++; }
            leak = std::max(0.0F, leak + ((i%3U)==0U?0.05F:-0.02F));
            if (d[i]>1.0){ warns++; }
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" flow="<<flow<<" leak="<<leak<<"\n"; }
        }
        std::cout<<"trips="<<trips<<" warns="<<warns<<"\n";
    }
}
int main(){ fusion_077::monitor(); return 0; }
