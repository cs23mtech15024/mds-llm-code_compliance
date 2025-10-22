// Context: Automotive CAN diagnostics poller

#include <iostream>
int main(){
    unsigned req=0U, resp=0U;    // NC
    int err=0, retries=0;        // NC
    bool ok=false, timeout=false;// NC
    std::cout<<req<<","<<resp<<","<<err<<","<<retries<<","<<ok<<","<<timeout<<"\n";
    return 0;
}
