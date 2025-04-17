/*
Question 17: Write a program in C to print all the alphabets using a pointer.

This program demonstrates:
- How to use pointers to traverse through alphabets
- How to use pointer arithmetic with character arrays
- How to handle character ranges and bounds

Questions to consider:
1. How does pointer arithmetic work with characters?
2. Why might we want to use pointers for character traversal?
3. How can we handle both uppercase and lowercase alphabets?
4. What are the advantages of using pointers for character operations?
5. How can we optimize the alphabet printing process?
*/

#include <stdio.h>

// Function prototypes
void printAlphabets(char *start, char *end);
void printAlphabetsReverse(char *start, char *end);

int main() {
    // Declare character arrays for alphabets
    char uppercase[27];
    char lowercase[27];
    char *ptr;
    
    printf("\nPrinting Alphabets Using Pointer:\n");
    printf("------------------------------\n");
    
    // Initialize arrays with alphabets
    ptr = uppercase;
    for(char ch = 'A'; ch <= 'Z'; ch++) {
        *ptr = ch;
        ptr++;
    }
    *ptr = '\0';  // Null terminate the string
    
    ptr = lowercase;
    for(char ch = 'a'; ch <= 'z'; ch++) {
        *ptr = ch;
        ptr++;
    }
    *ptr = '\0';  // Null terminate the string
    
    // Print uppercase alphabets
    printf("\nUppercase Alphabets (Forward):\n");
    printAlphabets(uppercase, uppercase + 25);
    
    printf("\nUppercase Alphabets (Reverse):\n");
    printAlphabetsReverse(uppercase, uppercase + 25);
    
    // Print lowercase alphabets
    printf("\nLowercase Alphabets (Forward):\n");
    printAlphabets(lowercase, lowercase + 25);
    
    printf("\nLowercase Alphabets (Reverse):\n");
    printAlphabetsReverse(lowercase, lowercase + 25);
    
    return 0;
}

// Function to print alphabets in forward order
void printAlphabets(char *start, char *end) {
    char *ptr = start;
    while(ptr <= end) {
        printf("%c ", *ptr);
        ptr++;
    }
    printf("\n");
}

// Function to print alphabets in reverse order
void printAlphabetsReverse(char *start, char *end) {
    char *ptr = end;
    while(ptr >= start) {
        printf("%c ", *ptr);
        ptr--;
    }
    printf("\n");
}