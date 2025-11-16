// Context: Neural network layer weights

// ------ Compliant Program (079_c.cpp)
// Context: Neural network layer weights
// Status: Array passed by reference (COMPLIANT)
#include <iostream>
#include <iomanip>

namespace nn_079_c {

static void init_first(float (&w)[784]){ w[0] = 0.01F; }

void initialize_weights(float (&weights)[784]) { // C API
    init_first(weights);
    std::cout << std::fixed << std::setprecision(5)
              << "w0=" << weights[0] << "\n";
}

static void dump_head(const float (&w)[784]){
    for(int i=0;i<5;i++){ std::cout << (i?",":"head:") << w[i]; }
    std::cout << "\n";
}

} // namespace nn_079_c

int main(){
    using namespace nn_079_c;
    float nn_weights[784] = {0.0F};
    initialize_weights(nn_weights);
    dump_head(nn_weights);
    return 0;
}
