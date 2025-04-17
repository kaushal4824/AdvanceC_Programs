/*
Question 5: Write a program in C to write multiple lines to a text file.

This program demonstrates:
- How to write multiple lines to a text file
- How to handle line-by-line input and writing
- How to use fprintf() for formatted output
- Proper file management and error handling

Concepts covered:
1. File opening in write mode
2. Line-by-line writing techniques
3. Dynamic line count handling
4. Error checking for write operations
5. Buffer management for input
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char line[100];  // Buffer for each line
    int num_lines;
    
    printf("\nMultiple Line Writing Demonstration:\n");
    printf("--------------------------------\n");
    
    // Get number of lines from user
    printf("How many lines do you want to write? (1-10): ");
    scanf("%d", &num_lines);
    getchar();  // Consume newline left by scanf
    
    // Input validation
    if(num_lines <= 0 || num_lines > 10) {
        printf("Invalid number of lines! Please enter between 1 and 10.\n");
        return 1;
    }
    
    // Open file in write mode
    file = fopen("multiline.txt", "w");
    
    // Check if file was opened successfully
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    printf("\nEnter %d lines of text:\n", num_lines);
    printf("------------------------\n");
    
    // Write lines to file
    for(int i = 0; i < num_lines; i++) {
        printf("Line %d: ", i + 1);
        
        // Get line from user
        if(fgets(line, sizeof(line), stdin) == NULL) {
            printf("Error reading input!\n");
            fclose(file);
            return 1;
        }
        
        // Write line to file
        if(fprintf(file, "%s", line) < 0) {
            printf("Error writing to file!\n");
            fclose(file);
            return 1;
        }
    }
    
    // Close the file
    fclose(file);
    
    printf("\nAll lines have been written to 'multiline.txt' successfully!\n");
    printf("You can check the file in the current directory.\n");
    
    return 0;
}