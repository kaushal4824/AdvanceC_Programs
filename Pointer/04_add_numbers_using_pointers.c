/*
Question 4: Write a program in C to add two numbers using pointers.

This program demonstrates:
- How to use pointers for basic arithmetic operations
- How to access and modify values through pointers
- How to work with multiple pointers

Questions to consider:
1. What happens if we try to add the pointer addresses instead of their values?
2. Can we use pointer arithmetic to add these numbers?
3. What are the benefits of using pointers for this simple operation?
4. How would this be useful in real-world applications?
*/

#include <stdio.h>

int main() {
    // Declare variables
    int num1 = 50;
    int num2 = 25;
    int sum = 0;
    
    // Declare pointers
    int *ptr1, *ptr2, *sum_ptr;
    
    // Initialize pointers
    ptr1 = &num1;
    ptr2 = &num2;
    sum_ptr = &sum;
    
    printf("\nAdding Numbers Using Pointers:\n");
    printf("---------------------------\n");
    
    // Display initial values
    printf("First number (num1): %d\n", num1);
    printf("Second number (num2): %d\n", num2);
    
    // Add numbers using pointers
    *sum_ptr = *ptr1 + *ptr2;
    
    printf("\nCalculation using pointers:\n");
    printf("*sum_ptr = *ptr1 + *ptr2\n");
    printf("%d = %d + %d\n", *sum_ptr, *ptr1, *ptr2);
    
    // Display the result
    printf("\nSum of the numbers: %d\n", sum);
    
    // Demonstrate pointer addresses
    printf("\nMemory Addresses:\n");
    printf("Address of num1: %p\n", (void*)ptr1);
    printf("Address of num2: %p\n", (void*)ptr2);
    printf("Address of sum: %p\n", (void*)sum_ptr);
    
    return 0;
}