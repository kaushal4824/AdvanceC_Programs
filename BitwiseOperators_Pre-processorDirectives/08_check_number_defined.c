/*
Program 8: Check if a number is defined using #define directive
This program demonstrates:
- Use of #define directive
- Conditional compilation
- Input validation
*/

#include <stdio.h>

// Define some numbers for testing
#define NUMBER_10 10
#define NUMBER_20 20
#define NUMBER_30 30

// Function to check if a number is defined
void checkNumberDefined(int num) {
    switch(num) {
        #ifdef NUMBER_10
        case 10:
            printf("%d is defined using #define\n", num);
            break;
        #endif
        
        #ifdef NUMBER_20
        case 20:
            printf("%d is defined using #define\n", num);
            break;
        #endif
        
        #ifdef NUMBER_30
        case 30:
            printf("%d is defined using #define\n", num);
            break;
        #endif
        
        default:
            printf("%d is not defined using #define\n", num);
    }
}

int main() {
    int number;
    
    printf("\nNumber Definition Checker\n");
    printf("----------------------\n");
    printf("(Numbers 10, 20, and 30 are defined)\n\n");
    
    // Input number with validation
    do {
        printf("Enter a number to check: ");
        if(scanf("%d", &number) != 1) {
            printf("Invalid input! Please enter a valid number.\n");
            while(getchar() != '\n'); // Clear input buffer
            continue;
        }
        break;
    } while(1);
    
    // Check if number is defined
    checkNumberDefined(number);
    
    return 0;
}