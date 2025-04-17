/*
Question 11: Write a program in C to find the factorial of a given number using pointers.

This program demonstrates:
- How to use pointers in recursive functions
- How to calculate factorial using pointer arithmetic
- How to handle large numbers and overflow conditions

Questions to consider:
1. How does using pointers in recursive functions affect memory usage?
2. What are the advantages of using pointers for factorial calculation?
3. How can we handle factorial overflow conditions?
4. What is the maximum factorial we can calculate with different data types?
5. How does this implementation compare to an iterative approach?
*/

#include <stdio.h>

// Function prototypes
void calculateFactorial(unsigned int n, unsigned long long *result);
void factorialRecursive(unsigned int *n, unsigned long long *result);

int main() {
    unsigned int num;
    unsigned long long factorial = 1;
    
    printf("\nCalculating Factorial Using Pointers:\n");
    printf("---------------------------------\n");
    
    // Get input from user
    printf("Enter a number (0-20): ");
    scanf("%u", &num);
    
    // Input validation
    if(num > 20) {
        printf("Number too large! Maximum value is 20 to avoid overflow.\n");
        return 1;
    }
    
    // Calculate factorial using iterative method
    calculateFactorial(num, &factorial);
    printf("\nFactorial using iterative method:\n");
    printf("%u! = %llu\n", num, factorial);
    
    // Reset factorial for recursive method
    factorial = 1;
    unsigned int temp = num;
    
    // Calculate factorial using recursive method
    factorialRecursive(&temp, &factorial);
    printf("\nFactorial using recursive method:\n");
    printf("%u! = %llu\n", num, factorial);
    
    return 0;
}

// Function to calculate factorial iteratively using pointers
void calculateFactorial(unsigned int n, unsigned long long *result) {
    *result = 1;
    
    for(unsigned int i = 1; i <= n; i++) {
        *result *= i;
    }
}

// Function to calculate factorial recursively using pointers
void factorialRecursive(unsigned int *n, unsigned long long *result) {
    if(*n <= 1) {
        return;
    }
    
    *result *= *n;
    (*n)--;
    factorialRecursive(n, result);
}