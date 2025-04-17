/*
Question 18: Write a program in C to print a string in reverse using a pointer.

This program demonstrates:
- How to traverse a string in reverse order using pointers
- How to handle string manipulation with pointer arithmetic
- How to work with string termination characters

Questions to consider:
1. How does pointer arithmetic work with strings?
2. What are the advantages of using pointers for string reversal?
3. How do we handle string boundaries safely?
4. What is the role of the null terminator in string reversal?
5. How can we optimize the string reversal process?
*/

#include <stdio.h>
#include <string.h>

// Function prototypes
void printStringReverse(const char *str);
void printStringReverseRecursive(const char *str);

int main() {
    char str[100];
    
    printf("\nPrinting String in Reverse Using Pointer:\n");
    printf("------------------------------------\n");
    
    // Get input string from user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove newline if present
    size_t len = strlen(str);
    if (len > 0 && str[len-1] == '\n') {
        str[len-1] = '\0';
        len--;
    }
    
    // Display original string
    printf("\nOriginal string: %s\n", str);
    
    // Print string in reverse using iterative method
    printf("\nReversed string (iterative method):\n");
    printStringReverse(str);
    
    // Print string in reverse using recursive method
    printf("\nReversed string (recursive method):\n");
    printStringReverseRecursive(str);
    printf("\n");
    
    return 0;
}

// Function to print string in reverse using pointer arithmetic
void printStringReverse(const char *str) {
    const char *end = str + strlen(str) - 1;  // Point to last character
    
    // Traverse from end to beginning
    while (end >= str) {
        printf("%c", *end);
        end--;
    }
    printf("\n");
}

// Function to print string in reverse using recursion
void printStringReverseRecursive(const char *str) {
    // Base case: if we've reached the end of string
    if (*str == '\0') {
        return;
    }
    
    // Recursive call with next character
    printStringReverseRecursive(str + 1);
    
    // Print current character
    printf("%c", *str);
}