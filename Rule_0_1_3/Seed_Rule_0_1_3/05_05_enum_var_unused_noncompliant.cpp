// Non-compliant: enum variable declared but never used.
enum Color { Red, Green, Blue };

int main() {
    Color c; // unused
    (void)sizeof(Color); // doesn't use 'c'
    return 0;
}
