// Context: Smart meter demand response

#include <iostream>
int main(){
    double kWh=0.0, price=6.2;    // NC
    bool peak=false, shed=false;  // NC
    int msgs=0, alerts=0;         // NC
    kWh += 1.5; peak = (price>7.0);
    std::cout<<kWh<<","<<price<<","<<peak<<","<<shed<<","<<msgs<<","<<alerts<<"\n";
    return 0;
}
