#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // 1. String literal
    printf("String literal: %s\n", "Hello, World!");

    // 2. Character array (including null terminator)
    char arrayStr[] = "Hello, World!";
    printf("Character array: %s (Size: %lu bytes)\n", arrayStr, sizeof(arrayStr));

    // 3. Pointer to string literal
    const char *ptrToStr = "Hello, World!";
    printf("Pointer to string literal: %s (Pointer size: %lu bytes)\n", ptrToStr, sizeof(ptrToStr));

    // 4. Dynamically allocated string
    char *dynStr = malloc(14); // "Hello, World!" is 13 characters + null terminator
    strcpy(dynStr, "Hello, World!");
    printf("Dynamically allocated string: %s (Allocated memory: 14 bytes)\n", dynStr);
    free(dynStr); // Remember to free the dynamically allocated memory

    return 0;
}
