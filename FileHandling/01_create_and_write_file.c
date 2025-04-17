/*
Question 1: Write a program to create a text file with the name sdata under current directory. 
It should be opened in w mode to write the data on it.

This program demonstrates:
- How to create a text file using fopen()
- How to write data to a file using fprintf()
- How to properly close a file using fclose()
- Basic file error handling

Concepts covered:
1. File pointer declaration and initialization
2. File opening in write mode ('w')
3. Error checking for file operations
4. Writing formatted output to a file
5. Proper file closure and resource management
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;    // File pointer declaration
    char data[100]; // Buffer to store user input
    
    printf("\nFile Creation and Writing Demonstration:\n");
    printf("-----------------------------------\n");
    
    // Open file in write mode
    file = fopen("sdata.txt", "w");
    
    // Check if file was opened successfully
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    printf("File 'sdata.txt' created successfully!\n\n");
    
    // Get data from user
    printf("Enter data to write to the file: ");
    fgets(data, sizeof(data), stdin);
    
    // Write data to file
    fprintf(file, "%s", data);
    
    // Close the file
    fclose(file);
    
    printf("\nData has been written to file successfully!\n");
    printf("You can check 'sdata.txt' in the current directory.\n");
    
    return 0;
}