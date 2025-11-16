// Context: Drone propeller pitch lookup header

// -------- Non-Compliant Program (prog_067_nc.cpp)
#include <iostream>
#include "seedNC.h"

namespace pitch_nc {

void test(int idx[], std::size_t n){ // NC decay
    for(size_t i=0;i<n;++i){
        float p = seed067_get_pitch(idx[i]);
        std::cout << "idx=" << idx[i]
                  << " p=" << p
                  << " v0=" << seed067_pitch_values[0]
                  << "\n";
    }
}

int maxidx(int arr[], std::size_t n){ int m=arr[0]; for(size_t i=1;i<n;++i) if(arr[i]>m)m=arr[i]; return m; }

} // namespace pitch_nc

int main(){
    using namespace pitch_nc;
    int i[5]={0,1,2,1,0};
    test(i,5);
    std::cout << "maxidx=" << maxidx(i,5)<<"\n";
    return 0;
}
