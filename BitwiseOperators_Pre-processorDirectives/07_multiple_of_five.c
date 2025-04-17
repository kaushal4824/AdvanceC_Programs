/*
Program 7: Check if a number is a multiple of 5 using conditional directives
This program demonstrates:
- Use of conditional directives (#if, #else)
- Macro definitions
- Input validation
*/

#include <stdio.h>

// Macro to check if a number is multiple of 5
#define IS_MULTIPLE_OF_5(num) ((num) % 5 == 0)

int main() {
    int number;
    
    printf("\nMultiple of 5 Checker\n");
    printf("-------------------\n");
    
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
    
    // Check if number is multiple of 5 using conditional directives
    #if 1 // This block will always be compiled
        if(IS_MULTIPLE_OF_5(number)) {
            printf("\n%d is a multiple of 5.\n", number);
        } else {
            printf("\n%d is not a multiple of 5.\n", number);
        }
    #endif
    
    return 0;
}