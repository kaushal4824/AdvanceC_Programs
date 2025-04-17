/*
Program 4: Find maximum of three numbers using #define preprocessor directive
This program demonstrates:
- Use of macro definitions
- Nested macro expansion
- Input validation
*/

#include <stdio.h>

// Macro to find maximum of two numbers
#define MAX(a, b) ((a) > (b) ? (a) : (b))

// Macro to find maximum of three numbers using MAX macro
#define MAX3(a, b, c) (MAX(MAX(a, b), c))

int main() {
    int num1, num2, num3;
    
    printf("\nMaximum Number Finder\n");
    printf("-------------------\n");
    
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
    
    // Input third number with validation
    do {
        printf("Enter third number: ");
        if(scanf("%d", &num3) != 1) {
            printf("Invalid input! Please enter a valid number.\n");
            while(getchar() != '\n'); // Clear input buffer
            continue;
        }
        break;
    } while(1);
    
    // Find and display maximum using macro
    printf("\nThe maximum number is: %d\n", MAX3(num1, num2, num3));
    
    return 0;
}