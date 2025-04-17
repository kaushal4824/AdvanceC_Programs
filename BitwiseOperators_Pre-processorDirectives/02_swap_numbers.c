/*
Program 2: Swap two numbers using bitwise XOR operator
This program demonstrates:
- Swapping numbers without using a temporary variable
- Use of XOR bitwise operator
- Input validation
*/

#include <stdio.h>

// Function prototype
void swapNumbers(int *a, int *b);

int main() {
    int num1, num2;
    
    printf("\nNumber Swapping using Bitwise XOR\n");
    printf("-------------------------------\n");
    
    // Input first number with validation
    do {
        printf("Enter first number: ");
        if(scanf("%d", &num1) != 1) {
            printf("Invalid input! Please enter a valid number.\n");
            while(getchar() != '\n'); // Clear input buffer
            continue;
        }
        break;
    } while(1);
    
    // Input second number with validation
    do {
        printf("Enter second number: ");
        if(scanf("%d", &num2) != 1) {
            printf("Invalid input! Please enter a valid number.\n");
            while(getchar() != '\n'); // Clear input buffer
            continue;
        }
        break;
    } while(1);
    
    printf("\nBefore swapping:\n");
    printf("First number: %d\n", num1);
    printf("Second number: %d\n", num2);
    
    // Swap numbers using bitwise XOR
    swapNumbers(&num1, &num2);
    
    printf("\nAfter swapping:\n");
    printf("First number: %d\n", num1);
    printf("Second number: %d\n", num2);
    
    return 0;
}

// Function to swap numbers using XOR
void swapNumbers(int *a, int *b) {
    // Using XOR to swap numbers without temporary variable
    *a = *a ^ *b;    // a = a XOR b
    *b = *a ^ *b;    // b = (a XOR b) XOR b = a
    *a = *a ^ *b;    // a = (a XOR b) XOR a = b
}