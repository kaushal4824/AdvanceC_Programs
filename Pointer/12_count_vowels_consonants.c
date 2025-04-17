/*
Question 12: Write a program in C to count the number of vowels and consonants in a string using a pointer.

This program demonstrates:
- How to traverse a string using pointer arithmetic
- How to classify characters using pointer dereferencing
- How to count character types using pointer-based string processing

Questions to consider:
1. How does pointer arithmetic help in string traversal?
2. Why might we want to use pointers instead of array indexing?
3. How can we handle case sensitivity in character classification?
4. What are the potential issues with string bounds?
5. How can we optimize the character classification process?
*/

#include <stdio.h>
#include <ctype.h>

// Function prototypes
void countVowelsAndConsonants(const char *str, int *vowels, int *consonants);
int isVowel(char c);

int main() {
    char str[100];
    int vowels = 0, consonants = 0;
    
    printf("\nCounting Vowels and Consonants Using Pointer:\n");
    printf("----------------------------------------\n");
    
    // Get input string from user
    printf("Enter a string: ");
    scanf("%99[^\n]", str);
    
    // Count vowels and consonants
    countVowelsAndConsonants(str, &vowels, &consonants);
    
    // Display results
    printf("\nResults:\n");
    printf("String: %s\n", str);
    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);
    
    // Demonstrate character classification
    printf("\nCharacter Classification:\n");
    const char *ptr = str;
    int position = 0;
    
    while(*ptr != '\0') {
        if(isalpha(*ptr)) {
            printf("Character '%c' at position %d is a %s\n",
                   *ptr, position,
                   isVowel(*ptr) ? "vowel" : "consonant");
        }
        ptr++;
        position++;
    }
    
    return 0;
}

// Function to count vowels and consonants using pointer
void countVowelsAndConsonants(const char *str, int *vowels, int *consonants) {
    *vowels = 0;
    *consonants = 0;
    
    while(*str != '\0') {
        if(isalpha(*str)) {
            if(isVowel(*str)) {
                (*vowels)++;
            } else {
                (*consonants)++;
            }
        }
        str++;  // Move to next character
    }
}

// Function to check if a character is a vowel
int isVowel(char c) {
    c = tolower(c);  // Convert to lowercase for easier comparison
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}