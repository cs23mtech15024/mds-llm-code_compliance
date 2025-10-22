// Context: Smart city water leak localization

// ------ Non-Compliant Program (059_nc.cpp)
// Multi-declarator statements break 8-0-1.
#include <iostream>
#include <vector>
#include <cmath>
namespace leak_059 {
    struct Seg { double flow; double p; }; // OK
    static double score(double f,double p,double thr){ return (f>thr)?(f-thr)*p:0.0; }
    void localize(){
        double flow=20.0, press=3.5;           // NC
        float thr=0.5F, scoreAcc=0.0F;         // NC
        int zones=4, alarms=0;                 // NC
        std::vector<double> F{19.8,20.6,21.1,20.2};
        std::vector<double> P{3.5,3.4,3.3,3.6};
        for (int i=0;i<zones;++i){
            flow = F[i]; press = P[i];
            double s = score(flow,press,static_cast<double>(thr));
            if (s>0.8){ alarms++; }
            scoreAcc = static_cast<float>(scoreAcc + s);
            if ((i%2)==0){ std::cout<<"i="<<i<<" f="<<flow<<" p="<<press<<" s="<<s<<"\n"; }
        }
        std::cout<<"alarms="<<alarms<<" score="<<scoreAcc<<"\n";
    }
}
int main(){ leak_059::localize(); return 0; }
