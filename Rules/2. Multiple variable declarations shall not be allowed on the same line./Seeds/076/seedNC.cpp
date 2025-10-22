// Context: Marine buoy wave spectral estimator

#include <iostream>
int main(){
    float ax=0.0F, ay=0.0F;          // NC
    float az=0.0F, dt=0.05F;         // NC
    unsigned n=0U, spikes=0U;        // NC
    ax += 0.1F; ay -= 0.1F;
    std::cout<<ax<<","<<ay<<","<<az<<","<<dt<<","<<n<<","<<spikes<<"\n";
    return 0;
}
