/*
Question 10: Write a program in C to swap elements using call by reference.

This program demonstrates:
- How to swap values between variables using pointers
- How to implement a generic swap function
- How to use call by reference for efficient swapping

Questions to consider:
1. Why is swapping using pointers more efficient than using temporary variables?
2. How does call by reference help in swapping values?
3. Can we swap values without using a temporary variable?
4. What are the potential risks of swapping values using pointers?
5. How can we extend this concept to swap array elements?
*/

#include <stdio.h>

// Function prototypes
void swapIntegers(int *a, int *b);
void swapCharacters(char *a, char *b);
void swapFloats(float *a, float *b);

int main() {
    // Integer swap demonstration
    int num1 = 10, num2 = 20;
    
    // Character swap demonstration
    char char1 = 'A', char2 = 'B';
    
    // Float swap demonstration
    float float1 = 1.5f, float2 = 2.5f;
    
    printf("\nSwapping Elements Using Call by Reference:\n");
    printf("-------------------------------------\n");
    
    // Before swap
    printf("\nBefore Swapping:\n");
    printf("Integers: num1 = %d, num2 = %d\n", num1, num2);
    printf("Characters: char1 = %c, char2 = %c\n", char1, char2);
    printf("Floats: float1 = %.1f, float2 = %.1f\n", float1, float2);
    
    // Perform swaps
    swapIntegers(&num1, &num2);
    swapCharacters(&char1, &char2);
    swapFloats(&float1, &float2);
    
    // After swap
    printf("\nAfter Swapping:\n");
    printf("Integers: num1 = %d, num2 = %d\n", num1, num2);
    printf("Characters: char1 = %c, char2 = %c\n", char1, char2);
    printf("Floats: float1 = %.1f, float2 = %.1f\n", float1, float2);
    
    return 0;
}

// Function to swap integers
void swapIntegers(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to swap characters
void swapCharacters(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Function to swap floats
void swapFloats(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}