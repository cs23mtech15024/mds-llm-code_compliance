// Non-compliant: reference bound but never referenced.
int main() {
    int x = 5;
    int& ref = x; // unused
    return 0;
}
