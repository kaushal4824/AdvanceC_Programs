/*
Question 1: Write a program in C to show the basic declaration of a pointer.

This program demonstrates:
- How to declare a pointer variable
- How to assign address of a variable to a pointer
- How to access value using pointer dereference
- Different ways to use and display pointer information
*/

#include <stdio.h>

int main() {
    // Declaring a normal integer variable
    int num = 10;
    
    // Declaring a pointer variable that can store address of an integer
    int *ptr;
    
    // Storing the address of num in pointer ptr
    ptr = &num;
    
    printf("\nDemonstrating Basic Pointer Declaration and Usage:\n");
    printf("-----------------------------------------------\n");
    
    // Displaying the value of num directly
    printf("Value of num: %d\n", num);
    
    // Displaying the address of num using & operator
    printf("Address of num: %p\n", (void*)&num);
    
    // Displaying the value of pointer ptr (which is address of num)
    printf("Value stored in ptr (address): %p\n", (void*)ptr);
    
    // Displaying the value pointed to by ptr using * operator
    printf("Value pointed to by ptr: %d\n", *ptr);
    
    // Displaying the address of pointer ptr itself
    printf("Address of pointer ptr itself: %p\n", (void*)&ptr);
    
    // Modifying value through pointer
    *ptr = 20;
    printf("\nAfter modifying value through pointer (*ptr = 20):\n");
    printf("New value of num: %d\n", num);
    
    return 0;
}