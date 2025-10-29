// Context: Marine buoy wave spectral estimator

#include <iostream>
int main(){
    float ax=0.0F;        // C
    float ay=0.0F;        // C
    float az=0.0F;        // C
    float dt=0.05F;       // C
    unsigned n=0U;        // C
    unsigned spikes=0U;   // C
    ax += 0.1F; ay -= 0.1F;
    std::cout<<ax<<","<<ay<<","<<az<<","<<dt<<","<<n<<","<<spikes<<"\n";
    return 0;
}
