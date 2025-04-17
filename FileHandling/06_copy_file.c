/*
Question 6: Write a program in C to copy a file to another name.

This program demonstrates:
- How to copy contents from one file to another
- How to handle file reading and writing simultaneously
- How to use different file modes for source and destination files
- Error handling for file operations

Concepts covered:
1. Opening multiple files simultaneously
2. Reading from source file
3. Writing to destination file
4. Buffer management for file operations
5. Error handling for both files
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *source_file, *dest_file;
    char ch;
    char source_name[100], dest_name[100];
    
    printf("\nFile Copy Demonstration:\n");
    printf("----------------------\n");
    
    // Get source file name
    printf("Enter source file name: ");
    scanf("%99s", source_name);
    
    // Get destination file name
    printf("Enter destination file name: ");
    scanf("%99s", dest_name);
    
    // Open source file in read mode
    source_file = fopen(source_name, "r");
    if (source_file == NULL) {
        printf("Error: Cannot open source file '%s'!\n", source_name);
        return 1;
    }
    
    // Open destination file in write mode
    dest_file = fopen(dest_name, "w");
    if (dest_file == NULL) {
        printf("Error: Cannot create destination file '%s'!\n", dest_name);
        fclose(source_file);
        return 1;
    }
    
    // Copy contents character by character
    while ((ch = fgetc(source_file)) != EOF) {
        if (fputc(ch, dest_file) == EOF) {
            printf("Error: Failed to write to destination file!\n");
            fclose(source_file);
            fclose(dest_file);
            return 1;
        }
    }
    
    // Check for read error
    if (ferror(source_file)) {
        printf("Error: Failed to read from source file!\n");
        fclose(source_file);
        fclose(dest_file);
        return 1;
    }
    
    // Close both files
    fclose(source_file);
    fclose(dest_file);
    
    printf("\nFile copied successfully!\n");
    printf("Contents of '%s' have been copied to '%s'\n", source_name, dest_name);
    
    return 0;
}