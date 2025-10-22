// Context: Telecom base-station power budget

// ------ Non-Compliant Program (029_nc.cpp)
// Groups multiple declarators; violates 8-0-1.
#include <iostream>
#include <vector>
#include <numeric>
namespace bs_029 {
    struct Channel { double w; }; // OK
    static double sum(const std::vector<Channel>& v){ return std::accumulate(v.begin(),v.end(),0.0,[](double a,const Channel& c){return a+c.w;}); }
    void budget(){
        double rf=800.0, bb=200.0;             // NC
        double aux=30.0, total=0.0;            // NC
        unsigned sectors=3U, alarms=0U;        // NC
        std::vector<Channel> ch{{rf},{bb},{aux}};
        total = rf+bb+aux;
        if (total>1100.0){ alarms++; }
        std::cout<<"total="<<total<<" sec="<<sectors<<" alarms="<<alarms<<" sum="<<sum(ch)<<"\n";
    }
}
int main(){ bs_029::budget(); return 0; }
