#include <stdio.h>

// Inline function declaration
inline int max(int a, int b) {
    return a > b ? a : b;
}

void sayHello() {
    printf("Hello, World!\n");
}

// Function declaration with parameters and return type
int add(int a, int b);

void greet();

int main() {
  
    int maximum = max(10, 5); // Inline function call
    printf("Maximum: %d\n", maximum);

    void (*funcPtr)() = sayHello;
    // Function call through pointer
    funcPtr();

    int sum = add(5, 3); // Standard unction cal

    greet();
  
    return 0;
}

int add(int a, int b) {
    return a + b;
}

void greet() {
    printf("Hello, World!\n");
}
