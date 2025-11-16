// Context: Voice recognition MFCC features

// Seed 071 — NC: MFCC features decay to pointer
#include <iostream>
void extract_mfcc(float features[]) { // NC
    features[0] = features[0] * 0.5F;
    std::cout << "mfcc0=" << features[0] << "\n";
}
int main(){
    float mfcc_coeffs[13] = {1.5F};
    extract_mfcc(mfcc_coeffs);
    return 0;
}