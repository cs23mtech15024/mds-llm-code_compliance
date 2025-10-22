// Context: Telecom base-station power budget

// ------ Compliant Program (029_c.cpp)
// Compliant: single declarator per declaration.
#include <iostream>
#include <vector>
#include <numeric>
namespace bs_029 {
    struct Channel { double w; }; // OK
    static double sum(const std::vector<Channel>& v){ return std::accumulate(v.begin(),v.end(),0.0,[](double a,const Channel& c){return a+c.w;}); }
    void budget(){
        double rf=800.0;                          // C
        double bb=200.0;                          // C
        double aux=30.0;                          // C
        double total=0.0;                         // C
        unsigned sectors=3U;                      // C
        unsigned alarms=0U;                       // C
        std::vector<Channel> ch{{rf},{bb},{aux}};
        total = rf+bb+aux;
        if (total>1100.0){ alarms++; }
        std::cout<<"total="<<total<<" sec="<<sectors<<" alarms="<<alarms<<" sum="<<sum(ch)<<"\n";
    }
}
int main(){ bs_029::budget(); return 0; }
