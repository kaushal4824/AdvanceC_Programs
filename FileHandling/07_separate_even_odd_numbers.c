/*
Question 7: Write a program to read n integer numbers from keyboard and store them into a file All.txt.
From the file All.txt, separate even and odd numbers and store them into files Even.txt and Odd.txt respectively.
Display contents of all the three files.

This program demonstrates:
- How to handle multiple files simultaneously
- How to process numbers and categorize them
- How to read and write numbers to files
- Error handling for multiple file operations

Concepts covered:
1. Multiple file pointer management
2. Number processing and categorization
3. File reading and writing operations
4. Error handling for multiple files
5. File content display techniques
*/

#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void displayFileContents(const char* filename);

int main() {
    FILE *all_file, *even_file, *odd_file;
    int num, count;
    
    printf("\nNumber Separation Demonstration:\n");
    printf("----------------------------\n");
    
    // Get count of numbers
    printf("How many numbers do you want to enter? (1-100): ");
    scanf("%d", &count);
    
    // Input validation
    if(count <= 0 || count > 100) {
        printf("Invalid count! Please enter between 1 and 100.\n");
        return 1;
    }
    
    // Open All.txt in write mode
    all_file = fopen("All.txt", "w");
    if (all_file == NULL) {
        printf("Error creating All.txt!\n");
        return 1;
    }
    
    // Input numbers and write to All.txt
    printf("\nEnter %d numbers:\n", count);
    for(int i = 0; i < count; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &num);
        fprintf(all_file, "%d\n", num);
    }
    
    fclose(all_file);
    
    // Reopen All.txt in read mode
    all_file = fopen("All.txt", "r");
    if (all_file == NULL) {
        printf("Error opening All.txt for reading!\n");
        return 1;
    }
    
    // Open Even.txt and Odd.txt in write mode
    even_file = fopen("Even.txt", "w");
    odd_file = fopen("Odd.txt", "w");
    
    if (even_file == NULL || odd_file == NULL) {
        printf("Error creating output files!\n");
        fclose(all_file);
        if (even_file) fclose(even_file);
        if (odd_file) fclose(odd_file);
        return 1;
    }
    
    // Read numbers from All.txt and categorize
    while (fscanf(all_file, "%d", &num) == 1) {
        if (num % 2 == 0) {
            fprintf(even_file, "%d\n", num);
        } else {
            fprintf(odd_file, "%d\n", num);
        }
    }
    
    // Close all files
    fclose(all_file);
    fclose(even_file);
    fclose(odd_file);
    
    // Display contents of all files
    printf("\nContents of All.txt:\n");
    printf("-------------------\n");
    displayFileContents("All.txt");
    
    printf("\nContents of Even.txt:\n");
    printf("--------------------\n");
    displayFileContents("Even.txt");
    
    printf("\nContents of Odd.txt:\n");
    printf("-------------------\n");
    displayFileContents("Odd.txt");
    
    return 0;
}

// Function to display contents of a file
void displayFileContents(const char* filename) {
    FILE *file = fopen(filename, "r");
    int num;
    
    if (file == NULL) {
        printf("Error opening %s!\n", filename);
        return;
    }
    
    while (fscanf(file, "%d", &num) == 1) {
        printf("%d\n", num);
    }
    
    fclose(file);
}