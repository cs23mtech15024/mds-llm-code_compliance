// Context: Neural network layer weights

// Seed 079 — NC: layer weights decay to pointer
#include <iostream>
void initialize_weights(float weights[]) { // NC
    weights[0] = 0.01F;
    std::cout << "w0=" << weights[0] << "\n";
}
int main(){
    float nn_weights[784] = {0};
    initialize_weights(nn_weights);
    return 0;
}