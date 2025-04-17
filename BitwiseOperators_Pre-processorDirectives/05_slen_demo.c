/*
Program: slen_demo.c
Demonstrates the usage of slen.h header file for string length calculation
*/

#include <stdio.h>
#include "05_slen.h"

int main() {
    char input[100];
    
    printf("\nString Length Calculator Demo:\n");
    printf("---------------------------\n");
    
    // Get input string from user
    printf("Enter a string: ");
    scanf("%99[^\n]", input);  // Safe input with limit
    
    // Calculate string length using slen function
    int length = slen(input);
    
    // Display results
    printf("\nString: %s\n", input);
    printf("Length: %d\n", length);
    
    // Demonstrate character-by-character analysis
    printf("\nCharacter Analysis:\n");
    for(int i = 0; i < length; i++) {
        printf("Position %d: '%c'\n", i, input[i]);
    }
    
    return 0;
}