// Context: Telecom base-station power budget

#include <iostream>
int main(){
    double rf=800.0;       // C
    double bb=200.0;       // C
    double aux=30.0;       // C
    double total=0.0;      // C
    unsigned sectors=3U;   // C
    unsigned alarms=0U;    // C
    total = rf+bb+aux;
    std::cout<<total<<","<<sectors<<","<<alarms<<"\n";
    return 0;
}
