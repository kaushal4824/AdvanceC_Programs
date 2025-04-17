/*
Program 6: Check if a number is even or odd using conditional directives
This program demonstrates:
- Use of conditional directives (#if, #else)
- Macro definitions
- Input validation
*/

#include <stdio.h>

// Macro to check if a number is even
#define IS_EVEN(num) ((num) % 2 == 0)

int main() {
    int number;
    
    printf("\nEven/Odd Number Checker\n");
    printf("--------------------\n");
    
    // Input number with validation
    do {
        printf("Enter a number: ");
        if(scanf("%d", &number) != 1) {
            printf("Invalid input! Please enter a valid number.\n");
            while(getchar() != '\n'); // Clear input buffer
            continue;
        }
        break;
    } while(1);
    
    // Check if number is even or odd using conditional directives
    #if 1 // This block will always be compiled
        if(IS_EVEN(number)) {
            printf("\n%d is an even number.\n", number);
        } else {
            printf("\n%d is an odd number.\n", number);
        }
    #endif
    
    return 0;
}