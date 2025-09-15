// Non-compliant: pointer to string literal never used.
int main() {
    const char* msg = "debug"; // unused
    return 0;
}
