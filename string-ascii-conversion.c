#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a string to a series of numbers (ASCII values)
void stringToNumbers(char *inputString) {
    for (int i = 0; inputString[i] != '\0'; i++) {
        printf("%d ", inputString[i]); // Print ASCII value of each character followed by a space
    }
    printf("\n");
}

// Function to convert a series of numbers (ASCII values) back to a string
void numbersToString(int *numbers, int length) {
    char *resultString = (char *)malloc(length + 1); // Allocate memory for the result string
    for (int i = 0; i < length; i++) {
        resultString[i] = (char)numbers[i]; // Convert each number to its corresponding ASCII character
    }
    resultString[length] = '\0'; // Null-terminate the string
    printf("%s\n", resultString);
    free(resultString); // Free the allocated memory
}

int main() {
    char *originalString = "Hello, World!";
    printf("Original String: %s\n", originalString);
    
    // Convert string to numbers
    printf("String to Numbers: ");
    stringToNumbers(originalString);
    
    // Assuming we have an array of numbers (ASCII values) for "Hello, World!"
    int numbers[] = {72, 101, 108, 108, 111, 44, 32, 87, 111, 114, 108, 100, 33};
    int length = sizeof(numbers) / sizeof(numbers[0]); // Calculate the length of the numbers array
    
    // Convert numbers back to string
    printf("Numbers to String: ");
    numbersToString(numbers, length);
    
    return 0;
}
