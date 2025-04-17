/*
Question 19: Write a C program and take the file name as a command line argument and write the message in the file.

This program demonstrates:
- Command line argument handling in C
- Basic file operations
- Error handling for file operations
- Writing text to files
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *file;
    char message[1000];
    
    printf("\nWrite Message to File Program:\n");
    printf("---------------------------\n");
    
    // Check if filename is provided
    if(argc != 2) {
        printf("Error: Please provide a filename as argument.\n");
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    
    // Open file in write mode
    file = fopen(argv[1], "w");
    if(file == NULL) {
        printf("Error opening file %s!\n", argv[1]);
        return 1;
    }
    
    // Get message from user
    printf("\nEnter the message to write to %s:\n", argv[1]);
    printf("(Press Enter and Ctrl+Z on a new line to finish)\n");
    
    // Read multiple lines until EOF (Ctrl+Z)
    while(fgets(message, sizeof(message), stdin) != NULL) {
        fprintf(file, "%s", message);
    }
    
    // Close file
    fclose(file);
    
    printf("\nMessage has been written to %s successfully!\n", argv[1]);
    
    return 0;
}