/*
Question 3: Reading a string (Character by character) from a file.

This program demonstrates:
- How to read a file character by character using fgetc()
- How to handle end-of-file (EOF) condition
- Basic file input operations
- Error handling for file operations

Concepts covered:
1. File opening in read mode ('r')
2. Character-by-character file reading
3. EOF detection and handling
4. File stream positioning
5. Error checking for file operations
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char ch;
    
    printf("\nReading File Character by Character Demonstration:\n");
    printf("------------------------------------------\n");
    
    // Open file in read mode
    file = fopen("sdata.txt", "r");
    
    // Check if file exists
    if (file == NULL) {
        printf("Error: File 'sdata.txt' not found!\n");
        printf("Please create the file first using programs 1 or 2.\n");
        return 1;
    }
    
    printf("\nContents of file 'sdata.txt':\n");
    printf("---------------------------\n");
    
    // Read file character by character
    while ((ch = fgetc(file)) != EOF) {
        // Print each character
        putchar(ch);
    }
    
    // Check for read errors
    if (ferror(file)) {
        printf("\nError occurred while reading the file!\n");
        fclose(file);
        return 1;
    }
    
    // Close the file
    fclose(file);
    
    printf("\nFile reading completed successfully!\n");
    
    return 0;
}