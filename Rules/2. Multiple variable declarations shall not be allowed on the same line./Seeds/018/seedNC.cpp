// Context: Telecom base-station power budget

#include <iostream>
int main(){
    double rf=800.0, bb=200.0;       // NC
    double aux=30.0, total=0.0;      // NC
    unsigned sectors=3U, alarms=0U;  // NC
    total = rf+bb+aux;
    std::cout<<total<<","<<sectors<<","<<alarms<<"\n";
    return 0;
}
