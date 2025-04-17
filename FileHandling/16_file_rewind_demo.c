/*
Question 16: This program demonstrates the file an_2.txt which contains some information and calling rewind()
function makes the entire file read and open with the relevant information by setting it up before the
beginning of the text as shown in the output.

This program demonstrates:
- File pointer manipulation using rewind()
- Reading file contents multiple times
- Basic file operations and error handling
- File content display techniques
*/

#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void createSampleFile(const char *filename);
void displayFileContents(const char *filename);
void demonstrateRewind(const char *filename);

int main() {
    const char *filename = "an_2.txt";
    
    printf("\nFile Rewind Demonstration:\n");
    printf("-----------------------\n");
    
    // Create sample file with some content
    createSampleFile(filename);
    
    // Display original contents
    printf("\nOriginal file contents:\n");
    printf("--------------------\n");
    displayFileContents(filename);
    
    // Demonstrate rewind functionality
    printf("\nDemonstrating rewind() function:\n");
    printf("----------------------------\n");
    demonstrateRewind(filename);
    
    return 0;
}

// Function to create a sample file with some content
void createSampleFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    
    if(file == NULL) {
        printf("Error creating file!\n");
        return;
    }
    
    // Write some sample content
    fprintf(file, "Line 1: This is the first line of text.\n");
    fprintf(file, "Line 2: This demonstrates file handling in C.\n");
    fprintf(file, "Line 3: We will use rewind() to read this multiple times.\n");
    fprintf(file, "Line 4: File operations are essential in programming.\n");
    fprintf(file, "Line 5: This is the last line of our sample text.\n");
    
    fclose(file);
    printf("Sample file created successfully!\n");
}

// Function to display file contents
void displayFileContents(const char *filename) {
    FILE *file = fopen(filename, "r");
    char buffer[100];
    
    if(file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    // Read and display each line
    while(fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
    
    fclose(file);
}

// Function to demonstrate rewind functionality
void demonstrateRewind(const char *filename) {
    FILE *file = fopen(filename, "r");
    char buffer[100];
    int count = 0;
    
    if(file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    printf("First read:\n");
    printf("-----------\n");
    while(fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
        count++;
    }
    
    // Use rewind to move file pointer back to beginning
    rewind(file);
    
    printf("\nAfter rewind() - Second read:\n");
    printf("---------------------------\n");
    while(fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
    
    printf("\nTotal lines read in first pass: %d\n", count);
    
    fclose(file);
}