// Context: Smart meter demand response

// ------ Compliant Program (022_c.cpp)
// One declarator per declaration; identical logic otherwise.
#include <iostream>
#include <vector>
#include <numeric>
namespace sm_022 {
    struct Bucket { double kwh; }; // OK
    static double avg(const std::vector<Bucket>& v){ return v.empty()?0.0:std::accumulate(v.begin(),v.end(),0.0,[](double a,const Bucket& b){return a+b.kwh;})/static_cast<double>(v.size()); }
    void loop(){
        double kWh=0.0;                          // C
        double price=6.2;                        // C
        bool peak=false;                         // C
        bool shed=false;                         // C
        int msgs=0;                              // C
        int alerts=0;                            // C
        std::vector<Bucket> roll{{1.2},{1.7},{0.9},{1.4}};
        kWh = avg(roll);
        if (price>7.0){ peak=true; shed=true; alerts++; }
        if (kWh>5.0){ msgs+=2; }
        std::cout<<"kWh="<<kWh<<" price="<<price<<" peak="<<peak<<" shed="<<shed
                 <<" msgs="<<msgs<<" alerts="<<alerts<<"\n";
    }
}
int main(){ sm_022::loop(); return 0; }
