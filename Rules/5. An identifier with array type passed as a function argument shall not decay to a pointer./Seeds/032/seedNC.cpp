// Context: ADC sampling rate configurations

// Seed 032 — NC: ADC config array decays to pointer
#include <iostream>
void configure_adc(int sample_rates[]) { // NC
    sample_rates[0] = 1000;
    std::cout << "adc0_rate=" << sample_rates[0] << "\n";
}
int main(){
    int adc_rates[8] = {0};
    configure_adc(adc_rates);
    return 0;
}