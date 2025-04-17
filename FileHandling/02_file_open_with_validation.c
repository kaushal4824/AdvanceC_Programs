/*
Question 2: Write a program to create a text file with the name sdata under current directory 
and check for the correct opening of file.

This program demonstrates:
- How to create and open a file with proper error checking
- Different file opening modes and their meanings
- How to handle file opening errors gracefully
- Best practices for file validation

Concepts covered:
1. File pointer and its initialization
2. File access modes ('w', 'r', 'a', etc.)
3. Error handling using perror()
4. File existence checking
5. File permissions and access rights
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    FILE *file;
    
    printf("\nFile Opening with Validation Demonstration:\n");
    printf("-------------------------------------\n");
    
    // Try to open file in read mode first to check if it exists
    file = fopen("sdata.txt", "r");
    if (file != NULL) {
        printf("File 'sdata.txt' already exists!\n");
        fclose(file);
        
        // Ask user if they want to overwrite
        char choice;
        printf("Do you want to overwrite it? (y/n): ");
        scanf(" %c", &choice);
        
        if (choice != 'y' && choice != 'Y') {
            printf("Operation cancelled.\n");
            return 0;
        }
    }
    
    // Open file in write mode
    file = fopen("sdata.txt", "w");
    
    // Check if file opened successfully
    if (file == NULL) {
        // Use perror to print system error message
        perror("Error opening file");
        return errno;
    }
    
    printf("\nFile 'sdata.txt' opened successfully in write mode!\n");
    printf("File validation checks passed.\n");
    
    // Write a test message to verify write access
    if (fprintf(file, "File access test successful!\n") < 0) {
        perror("Error writing to file");
        fclose(file);
        return errno;
    }
    
    // Close the file
    fclose(file);
    
    printf("\nFile operations completed successfully!\n");
    printf("You can check 'sdata.txt' in the current directory.\n");
    
    return 0;
}