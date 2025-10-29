// Context: Passport scanner OCR validator

#include <iostream>
int main(){
    float confidence=0.95F, threshold=0.9F; // NC
    int pages=32, errors=0;               // NC
    bool mrz=true, photo=true;            // NC
    confidence += 0.01F; pages++;
    std::cout<<confidence<<","<<threshold<<","<<pages<<","<<errors<<","<<mrz<<","<<photo<<"\n";
    return 0;
}
