1. Allocating Memory for a Single Integer
```
int *ptr = malloc(sizeof(int)); // Allocate memory for one integer
if (ptr != NULL) {
    *ptr = 10; // Assign a value
    printf("%d\n", *ptr); // Use the allocated memory
    free(ptr); // Free the allocated memory
}
```

2. Allocating Memory for an Array of Integers
```
int n = 5;
int *arr = calloc(n, sizeof(int)); // Allocate and zero-initialize array for 5 integers
if (arr != NULL) {
    for(int i = 0; i < n; i++) {
        arr[i] = i * i; // Initialize elements
    }
    free(arr); // Free the allocated memory
}
```

3. Resizing an Allocated Array
```
int *arr = malloc(5 * sizeof(int)); // Allocate memory for 5 integers
if (arr != NULL) {
    arr = realloc(arr, 10 * sizeof(int)); // Resize the array to 10 integers
    if (arr != NULL) {
        free(arr); // Free the resized memory
    }
}
```

4. Allocating Memory for a Struct
```
typedef struct {
    int id;
    float score;
} Student;

Student *s = malloc(sizeof(Student)); // Allocate memory for a Student struct
if (s != NULL) {
    s->id = 1;
    s->score = 96.5;
    printf("ID: %d, Score: %.2f\n", s->id, s->score);
    free(s); // Free the allocated memory
}
```

5. Using alloca for Stack Allocation
```
#include <alloca.h>

void function() {
    int n = 5;
    int *arr = alloca(n * sizeof(int)); // Allocate memory on the stack for 5 integers
    for (int i = 0; i < n; i++) {
        arr[i] = i; // Initialize elements
    }
    // No need to free, as memory is automatically reclaimed when the function returns
}
```

6. Varying memory allocation for same string / functionality:
Using malloc
```
char *str = (char *)malloc(6 * sizeof(char)); // Allocate memory for 5 characters + '\0'
if (str != NULL) {
    strcpy(str, "Hello"); // Copy string into allocated memory
    printf("%s\n", str);
    free(str); // Free the allocated memory
}
```
Using calloc
```
char *str = (char *)calloc(6, sizeof(char)); // Allocate and zero-initialize memory for 5 characters + '\0'
if (str != NULL) {
    strcpy(str, "Hello");
    printf("%s\n", str);
    free(str); // Free the allocated memory
}
```
Using realloc
```
char *str = (char *)malloc(3 * sizeof(char)); // Initial allocation
if (str != NULL) {
    strcpy(str, "Hi");
    str = (char *)realloc(str, 6 * sizeof(char)); // Resize block for new string
    if (str != NULL) {
        strcpy(str, "Hello");
        printf("%s\n", str);
        free(str); // Free the reallocated memory
    }
}
```

Although you cannot allocate memory for a function itself (since functions are not objects you can allocate memory for in C), you can dynamically allocate memory for function pointers. However, this is less common and usually not necessary.
```
void (**funcPtr)() = malloc(sizeof(&myFunction)); // Allocate memory for a function pointer
if (funcPtr != NULL) {
    *funcPtr = myFunction; // Assign the function address to the allocated pointer
    (*funcPtr)(); // Call the function
    free(funcPtr); // Free the allocated memory
}
```
Using an Array of Function Pointers
This is useful when you want to dynamically allocate an array of function pointers, for instance, to store different functions in a table.
```
void (**funcPtrArray)() = calloc(1, sizeof(&myFunction)); // Allocate memory for an array of 1 function pointer
if (funcPtrArray != NULL) {
    funcPtrArray[0] = myFunction; // Assign the function to the first element
    funcPtrArray[0](); // Call the function
    free(funcPtrArray); // Free the allocated memory
}
```


