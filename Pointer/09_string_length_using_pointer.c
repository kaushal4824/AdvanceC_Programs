/*
Question 9: Write a program in C to calculate the length of a string using a pointer.

This program demonstrates:
- How to traverse a string using pointer arithmetic
- How to count characters without using string library functions
- How to handle null-terminated strings

Questions to consider:
1. How does pointer arithmetic help in string traversal?
2. Why do we need to check for null terminator ('\0')?
3. How does this method compare to using strlen() function?
4. What happens if the string is not null-terminated?
5. Can we optimize this code for better performance?
*/

#include <stdio.h>

// Function prototype
int calculateLength(const char *str);

int main() {
    char str[100];
    
    printf("\nCalculating String Length Using Pointer:\n");
    printf("----------------------------------\n");
    
    // Get input string from user
    printf("Enter a string: ");
    scanf("%99[^\n]", str);  // Safe input with limit
    
    // Calculate length using pointer arithmetic
    int length = calculateLength(str);
    
    // Display results
    printf("\nString: %s\n", str);
    printf("Length: %d\n", length);
    
    // Demonstrate pointer traversal
    printf("\nDemonstrating pointer traversal:\n");
    const char *ptr = str;
    int position = 0;
    
    while(*ptr != '\0') {
        printf("Character at position %d: %c\n", position, *ptr);
        ptr++;      // Move to next character
        position++; // Increment position counter
    }
    
    return 0;
}

// Function to calculate string length using pointer
int calculateLength(const char *str) {
    const char *ptr = str;  // Start from beginning of string
    
    // Traverse until null terminator is found
    while(*ptr != '\0') {
        ptr++;  // Move to next character
    }
    
    // Return difference between final and initial positions
    return (int)(ptr - str);
}