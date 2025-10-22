// Context: Automotive CAN diagnostics poller

#include <iostream>
int main(){
    unsigned req=0U;       // C
    unsigned resp=0U;      // C
    int err=0;             // C
    int retries=0;         // C
    bool ok=false;         // C
    bool timeout=false;    // C
    std::cout<<req<<","<<resp<<","<<err<<","<<retries<<","<<ok<<","<<timeout<<"\n";
    return 0;
}
