/*
Question 8: Write a program in C to print all permutations of a given string using pointers.

This program demonstrates:
- How to use pointers for string manipulation
- How to implement recursive algorithms using pointers
- How to swap characters in a string using pointers

Questions to consider:
1. How does passing a string by pointer differ from passing by value?
2. Why do we need to use pointers for string manipulation in C?
3. How does the recursive approach work with pointers?
4. What are the memory considerations when generating all permutations?
5. How can we optimize this algorithm to handle longer strings?
*/

#include <stdio.h>
#include <string.h>

// Function prototypes
void generatePermutations(char *str, int start, int end);
void swap(char *x, char *y);

int main() {
    char str[100];
    
    printf("\nString Permutations Using Pointers:\n");
    printf("--------------------------------\n");
    
    // Get input string from user
    printf("Enter a string (max 8 characters): ");
    scanf("%s", str);
    
    // Input validation
    if(strlen(str) > 8) {
        printf("String too long! Please enter a string with max 8 characters.\n");
        return 1;
    }
    
    printf("\nAll possible permutations are:\n");
    generatePermutations(str, 0, strlen(str) - 1);
    
    return 0;
}

// Function to generate all permutations of a string
void generatePermutations(char *str, int start, int end) {
    if(start == end) {
        printf("%s\n", str);
        return;
    }
    
    for(int i = start; i <= end; i++) {
        // Swap characters
        swap((str + start), (str + i));
        
        // Recursive call
        generatePermutations(str, start + 1, end);
        
        // Backtrack (restore original string)
        swap((str + start), (str + i));
    }
}

// Function to swap two characters using pointers
void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}