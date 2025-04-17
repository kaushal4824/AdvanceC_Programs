/*
Question 4: Write a C program that counts the number of characters and number of lines in a file.

This program demonstrates:
- How to read and analyze file contents
- How to count characters and lines in a file
- How to handle different types of line endings
- Error handling for file operations

Concepts covered:
1. File reading operations
2. Character counting techniques
3. Line counting using newline detection
4. File stream error checking
5. Memory-efficient file processing
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char ch;
    int char_count = 0;
    int line_count = 0;
    int is_first_char = 1;  // Flag to handle empty file case
    
    printf("\nFile Character and Line Counter Demonstration:\n");
    printf("----------------------------------------\n");
    
    // Open file in read mode
    file = fopen("sdata.txt", "r");
    
    // Check if file exists
    if (file == NULL) {
        printf("Error: File 'sdata.txt' not found!\n");
        printf("Please create the file first using programs 1 or 2.\n");
        return 1;
    }
    
    // Read file character by character
    while ((ch = fgetc(file)) != EOF) {
        char_count++;  // Increment character count
        
        // Handle line counting
        if (is_first_char) {
            line_count = 1;  // First line
            is_first_char = 0;
        }
        if (ch == '\n') {
            line_count++;  // Increment line count for each newline
        }
    }
    
    // Handle empty file case
    if (is_first_char) {
        line_count = 0;
    }
    
    // Check for read errors
    if (ferror(file)) {
        printf("Error occurred while reading the file!\n");
        fclose(file);
        return 1;
    }
    
    // Display results
    printf("\nFile Analysis Results:\n");
    printf("--------------------\n");
    printf("Total characters: %d\n", char_count);
    printf("Total lines: %d\n", line_count);
    
    // Close the file
    fclose(file);
    
    return 0;
}