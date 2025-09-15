// Non-compliant: even volatile variables must be referenced.
int main() {
    volatile int status = 0; // unused
    (void)sizeof(status);    // sizeof does not access the object
    return 0;
}
