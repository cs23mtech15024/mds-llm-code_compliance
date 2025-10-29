// Context: Passport scanner OCR validator

#include <iostream>
int main(){
    float confidence=0.95F;    // C
    float threshold=0.9F;      // C
    int pages=32;              // C
    int errors=0;              // C
    bool mrz=true;             // C
    bool photo=true;           // C
    confidence += 0.01F; pages++;
    std::cout<<confidence<<","<<threshold<<","<<pages<<","<<errors<<","<<mrz<<","<<photo<<"\n";
    return 0;
}
