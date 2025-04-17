/*
Question 6: Write a program in C to find the maximum number between two numbers using a pointer.

This program demonstrates:
- How to use pointers for comparison operations
- How to implement a function that uses pointers to compare values
- How to return results through pointer parameters

Questions to consider:
1. Why might we want to use pointers for comparison operations?
2. How can we modify this program to find the minimum number as well?
3. What are the advantages of using pointer parameters over return values?
4. How could we extend this to compare more than two numbers?
5. What happens if we compare the pointer addresses instead of the values?
*/

#include <stdio.h>

// Function prototype
void findMax(int *num1, int *num2, int *max);

int main() {
    // Declare variables
    int first_num = 50;
    int second_num = 70;
    int max_num = 0;
    
    // Declare pointers
    int *ptr1, *ptr2, *max_ptr;
    
    // Initialize pointers
    ptr1 = &first_num;
    ptr2 = &second_num;
    max_ptr = &max_num;
    
    printf("\nFinding Maximum Number Using Pointers:\n");
    printf("----------------------------------\n");
    
    // Display initial values
    printf("First number: %d\n", *ptr1);
    printf("Second number: %d\n", *ptr2);
    
    // Find maximum using pointers
    findMax(ptr1, ptr2, max_ptr);
    
    // Display the result
    printf("\nMaximum number is: %d\n", *max_ptr);
    
    // Demonstrate pointer comparison
    printf("\nPointer Information:\n");
    printf("Address of first number: %p\n", (void*)ptr1);
    printf("Address of second number: %p\n", (void*)ptr2);
    printf("Address of maximum number: %p\n", (void*)max_ptr);
    
    return 0;
}

// Function to find maximum of two numbers using pointers
void findMax(int *num1, int *num2, int *max) {
    if(*num1 > *num2) {
        *max = *num1;
    } else {
        *max = *num2;
    }
    
    // Alternative way using conditional operator
    // *max = (*num1 > *num2) ? *num1 : *num2;
}