/*
Program 1: Convert decimal number to binary using bitwise operators
This program demonstrates:
- Use of bitwise operators for binary conversion
- Bit manipulation techniques
- Error handling for input validation
*/

#include <stdio.h>

// Function prototype
void decimalToBinary(int decimal);

int main() {
    int decimal;
    
    printf("\nDecimal to Binary Converter\n");
    printf("------------------------\n");
    
    // Input decimal number with validation
    do {
        printf("Enter a positive decimal number: ");
        if(scanf("%d", &decimal) != 1) {
            printf("Invalid input! Please enter a valid number.\n");
            while(getchar() != '\n'); // Clear input buffer
            continue;
        }
        
        if(decimal < 0) {
            printf("Please enter a positive number!\n");
            continue;
        }
        break;
    } while(1);
    
    printf("\nBinary representation of %d is: ", decimal);
    decimalToBinary(decimal);
    printf("\n");
    
    return 0;
}

// Function to convert decimal to binary using bitwise operators
void decimalToBinary(int decimal) {
    // Handle special case for 0
    if(decimal == 0) {
        printf("0");
        return;
    }
    
    // Find the position of the leftmost 1 bit
    int position = 31; // For 32-bit integer
    while(!(decimal & (1 << position)) && position >= 0) {
        position--;
    }
    
    // Print binary representation from left to right
    for(; position >= 0; position--) {
        printf("%d", (decimal & (1 << position)) ? 1 : 0);
        
        // Add space after every 4 bits for readability
        if(position % 4 == 0 && position != 0) {
            printf(" ");
        }
    }
}