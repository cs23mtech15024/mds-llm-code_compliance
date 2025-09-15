// Non-compliant: union object never referenced.
union U {
    int i;
    float f;
};

int main() {
    U u; // unused
    return 0;
}
