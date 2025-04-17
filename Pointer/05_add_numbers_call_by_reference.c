/*
Question 5: Write a program in C to add numbers using call by reference.

This program demonstrates:
- How to use call by reference to modify variables in different functions
- How pointers can be used to return multiple values from a function
- The difference between call by value and call by reference

Questions to consider:
1. What is the difference between call by value and call by reference?
2. Why would we choose to use call by reference instead of call by value?
3. How does the memory allocation differ between these two approaches?
4. Can we modify the original variables using call by value? Why or why not?
5. What are the potential risks of using call by reference?
*/

#include <stdio.h>

// Function prototypes
void addNumbers(int *num1, int *num2, int *result);
void displayResults(const int *num1, const int *num2, const int *sum);

int main() {
    // Declare variables
    int first_num = 10;
    int second_num = 20;
    int sum = 0;
    
    printf("\nAdding Numbers Using Call by Reference:\n");
    printf("-----------------------------------\n");
    
    // Display initial values
    printf("Initial values:\n");
    printf("First number: %d\n", first_num);
    printf("Second number: %d\n", second_num);
    
    // Call function using address of variables
    addNumbers(&first_num, &second_num, &sum);
    
    // Display results using another function
    displayResults(&first_num, &second_num, &sum);
    
    return 0;
}

// Function to add two numbers using pointers
void addNumbers(int *num1, int *num2, int *result) {
    // Add the values pointed to by num1 and num2
    *result = *num1 + *num2;
    
    // We can also modify the original numbers if needed
    // Uncomment the following lines to see how call by reference
    // allows us to modify the original variables
    /*
    *num1 = 100;  // Modifying first number
    *num2 = 200;  // Modifying second number
    */
}

// Function to display results using constant pointers
void displayResults(const int *num1, const int *num2, const int *sum) {
    printf("\nResults after addition:\n");
    printf("First number: %d\n", *num1);
    printf("Second number: %d\n", *num2);
    printf("Sum: %d\n", *sum);
    
    // Note: We can't modify the values here because of const keyword
    // *num1 = 500;  // This would cause a compilation error
}