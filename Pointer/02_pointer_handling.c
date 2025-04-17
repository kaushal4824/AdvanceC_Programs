/*
Question 2: Write a program in C to demonstrate how to handle pointers in a program.

This program demonstrates:
- Multiple levels of pointer indirection
- Pointer arithmetic
- Array access using pointers
- Common pointer operations and their effects
*/

#include <stdio.h>

int main() {
    // Declaring variables and pointers
    int num = 100;
    int *ptr1;      // Single pointer
    int **ptr2;     // Double pointer (pointer to pointer)
    int arr[5] = {10, 20, 30, 40, 50};
    int *arrPtr;
    
    // Initialize pointers
    ptr1 = &num;    // ptr1 points to num
    ptr2 = &ptr1;   // ptr2 points to ptr1
    arrPtr = arr;   // arrPtr points to first element of array
    
    printf("\nDemonstrating Multiple Levels of Pointers:\n");
    printf("-----------------------------------------\n");
    printf("Value of num: %d\n", num);
    printf("Value using single pointer (*ptr1): %d\n", *ptr1);
    printf("Value using double pointer (**ptr2): %d\n", **ptr2);
    
    printf("\nDemonstrating Pointer Arithmetic with Arrays:\n");
    printf("------------------------------------------\n");
    printf("Array values using pointer:\n");
    
    // Accessing array elements using pointer arithmetic
    for(int i = 0; i < 5; i++) {
        printf("*(arrPtr + %d): %d\n", i, *(arrPtr + i));
    }
    
    printf("\nModifying Values through Different Pointer Levels:\n");
    printf("------------------------------------------------\n");
    
    // Modifying value through single pointer
    *ptr1 = 200;
    printf("After *ptr1 = 200:\n");
    printf("num = %d\n", num);
    
    // Modifying value through double pointer
    **ptr2 = 300;
    printf("\nAfter **ptr2 = 300:\n");
    printf("num = %d\n", num);
    
    // Demonstrating pointer increment/decrement
    printf("\nPointer Increment/Decrement with Array:\n");
    printf("-------------------------------------\n");
    printf("Initial arrPtr points to: %d\n", *arrPtr);
    
    arrPtr++;  // Move to next element
    printf("After arrPtr++: %d\n", *arrPtr);
    
    arrPtr--;  // Move back to previous element
    printf("After arrPtr--: %d\n", *arrPtr);
    
    return 0;
}