#include <stdio.h>

// Simulating a class in C
typedef struct Person {
    char* name;
    void (*display)(struct Person*);
} Person;

void Person_display(Person* self) {
    printf("Name: %s\n", self->name);
}

Person createPerson(char* name) {
    Person p;
    p.name = name;
    p.display = Person_display; // Initialize the function pointer
    return p;
}

int main() {
  // Using the class-like structure
  Person john = createPerson("John Doe");
  john.display(&john); // Method call
  
  return 0;
}
