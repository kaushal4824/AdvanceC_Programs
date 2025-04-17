/*
Question 9: Write a program to accept a file name and print the contents of the file.

This program demonstrates:
- How to work with dynamic file names
- How to read and display file contents
- How to handle file errors gracefully
- Best practices for file operations

Concepts covered:
1. Dynamic file name handling
2. File opening and validation
3. Content reading and display
4. Error handling for file operations
5. Buffer management for file reading
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char filename[100];
    char buffer[1024];
    size_t bytes_read;
    
    printf("\nFile Content Display Demonstration:\n");
    printf("-------------------------------\n");
    
    // Get filename from user
    printf("Enter the name of the file to read: ");
    scanf("%99s", filename);
    
    // Open file in read mode
    file = fopen(filename, "r");
    
    // Check if file exists
    if (file == NULL) {
        printf("Error: Cannot open file '%s'!\n", filename);
        return 1;
    }
    
    printf("\nContents of file '%s':\n", filename);
    printf("------------------------\n");
    
    // Read and display file contents using buffer
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        fwrite(buffer, 1, bytes_read, stdout);
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