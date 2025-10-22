// Context: Smart meter demand response

#include <iostream>
int main(){
    double kWh=0.0;      // C
    double price=6.2;    // C
    bool peak=false;     // C
    bool shed=false;     // C
    int msgs=0;          // C
    int alerts=0;        // C
    kWh += 1.5; peak = (price>7.0);
    std::cout<<kWh<<","<<price<<","<<peak<<","<<shed<<","<<msgs<<","<<alerts<<"\n";
    return 0;
}
